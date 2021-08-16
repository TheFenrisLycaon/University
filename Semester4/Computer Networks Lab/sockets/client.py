import socket
import threading

nickname = input("What should we call you ::\t")
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 55555
client.connect((host, port))


def recieve():
    while True:
        try:
            message = client.recv(1024).decode('ascii')
            if message == 'NICK':
                client.send(nickname.encode('ascii'))
            else:
                print(message)
        except:
            print('Error occured !')
            break


def write():
    while True:
        msg = f'{nickname.upper()}::\t\t{input()}'
        client.send(msg.encode('ascii'))


recieveThread = threading.Thread(target=recieve)
recieveThread.start()
writingThread = threading.Thread(target=write)
writingThread.start()
