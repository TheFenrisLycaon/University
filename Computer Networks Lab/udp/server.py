import socket
import threading
import sys

host = '127.0.0.1'
port = 5555
server = socket.socket(socket.SO_REUSEADDR)
server.bind((host, port))
server.listen()
clients = []
nicknames = []

def broadcast(message):
    print(str(message.decode('utf-8')))
    for client in clients:
        client.send(message)


def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} left the chat !'.encode('utf-8'))
            nickname.remove(nickname)
            break


def recieve():
    while True:
        client, address = server.accept()
        print(f'Connected with {str(address)}')
        client.send("NICK".encode('utf-8'))
        nickname = client.recv(1024).decode('utf-8')
        nicknames.append(nickname)
        clients.append(client)
        broadcast(f'{nickname} has joined the chat !\n'.encode('utf-8'))
        client.send('Connected to the server !'.encode('utf-8'))
        thread = threading.Thread(target=handle, args=(client,))
        thread.start()


def write():
    while True:
        msg = f'Server::\t\t{input()}'
        if '/quit' not in msg:
            broadcast(msg.encode('utf-8'))
        else:
            recieveThread.join()
            writingThread.join()
            server.shutdown(socket.SHUT_RDWR)
            exit()


print("Server Started.")

try:
    recieveThread = threading.Thread(target=recieve)
    recieveThread.start()
    writingThread = threading.Thread(target=write)
    writingThread.start()
except (KeyboardInterrupt, SystemExit):
    recieveThread.join()
    writingThread.join()
    server.shutdown(socket.SHUT_RDWR)
    sys.exit()
