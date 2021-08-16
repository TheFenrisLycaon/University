import socket
import threading

host = '127.0.0.1'
port = 55555

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))
server.listen()

clients = []
nicknames = []


def kickUser(name):
    if name in nicknames:
        nameIndex = nicknames.index(name)
        clientKick = clients[nameIndex]
        clients.remove(clientKick)
        clientKick.send('You were kicked by the admin!'.encode('ascii'))
        clientKick.close()
        nicknames.remove(name)
    else:
        print(name)


def banUser(name):
    kickUser(name)
    with open('banned.txt', 'a') as f:
        f.write(f'{name}\n')
    f.close()


def broadcast(message):
    for client in clients:
        client.send(message)


def handle(client):
    while True:
        try:
            msg = message = client.recv(1024)

            if msg.decode('ascii').startswith('KICK'):
                if nicknames[clients.index(client)] == 'admin':
                    nameKick = msg.decode('ascii')
                    print(nameKick)
                    kickUser(nameKick('ascii')[5:])
                    broadcast(f"{nameKick[6:]} was kicked.".encode('ascii'))
                else:
                    client.send("Command was refused.".encode('ascii'))
            elif msg.decode('ascii').startswith('BAN'):
                if nicknames[clients.index(client)] == 'admin':
                    nameBan = msg.decode('ascii')[5:]
                    banUser(nameBan)
                    broadcast(f"{nameBan[5:]} was banned".encode('ascii'))
                else:
                    client.send("Command was refused.".encode('ascii'))
            else:
                broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} left the chat !'.encode('ascii'))
            nicknames.remove(nickname)
            break


def recieve():
    while True:
        client, address = server.accept()
        print(f'Connected with {str(address)}')

        client.send("NICK".encode('ascii'))
        nickname = client.recv(1024).decode('ascii')

        with open('banned.txt', 'r') as banned:
            bans = banned.readlines()

        if nickname+'\n' in bans:
            client.send('You are banned!'.encode('ascii'))
            client.close()
            continue

        if nickname == 'admin':
            client.send("ASKPASSWORD".encode('ascii'))
            passwd = client.recv(1024).decode('ascii')

            if passwd != 'adminpass':
                client.send('REFUSED'.encode('ascii'))
                client.close()
                continue

        nicknames.append(nickname)
        clients.append(client)

        broadcast(f'{nickname} has joined the chat !\n'.encode('ascii'))
        client.send('Connected to server !'.encode('ascii'))

        thread = threading.Thread(target=handle, args=(client,))
        thread.start()


print("Server Started.")
recieve()
