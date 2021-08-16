import socket
import threading

nickname = input("What should we call you ::\t")

if nickname == 'admin':
    passwd = input("Enter password::\t")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '127.0.0.1'
port = 55555

client.connect((host, port))

stopThread = False


def recieve():
    while True:
        global stopThread
        try:
            message = client.recv(1024).decode('ascii')
            if message == 'NICK':
                client.send(nickname.encode('ascii'))
                nextMessage = client.recv(1024).decode('ascii')
                if nextMessage == 'ASKPASSWORD':
                    client.send(passwd.encode('ascii'))
                    status = client.recv(1024).decode('ascii')
                    if status == 'REFUSED':
                        print("Wrong pasword... Connection Refused.")
                        stopThread = True
                elif nextMessage == 'BAN':
                    print('Connection refused due to ban.')
                    client.close()
                    stopThread = True

            else:
                print(message)

        except:
            print('Error occured !')
            break


def write():
    while True:
        if stopThread:
            break

        msg = f'{nickname.upper()}: {input()}'

        if msg[len(nickname)+2:].startswith('/'):
            if nickname != 'admin':
                print("Only for admins.")
            else:
                if msg[len(nickname)+2:].startswith('/kick'):
                    client.send(f"KICK {msg[4:]}".encode('ascii'))
                elif msg[len(nickname)+2:].startswith('/ban'):
                    client.send(f"BAN {msg[4:]}".encode('ascii'))

        client.send(msg.encode('ascii'))


recieveThread = threading.Thread(target=recieve)
recieveThread.start()

writingThread = threading.Thread(target=write)
writingThread.start()
