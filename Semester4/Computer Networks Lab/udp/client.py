import socket
import threading
import sys

nickname = input("What should we call you ::\t")
client = socket.socket(socket.SO_REUSEADDR)
host = '127.0.0.1'
port = 5555
client.connect((host, port))


def recieve():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == 'NICK':
                client.send(nickname.encode('utf-8'))
            else:
                print(str(message))
        except:
            print('Error occured !!')
            break


def write():
    while True:
        msg = f"{nickname.upper()}::\t\t{input()}"
        if '/quit' not in msg:
            client.send(msg.encode('utf-8'))
        else:
            recieveThread.join()
            writingThread.join()
            client.close()
            exit()

try:
    recieveThread = threading.Thread(target=recieve)
    recieveThread.start()
    writingThread = threading.Thread(target=write)
    writingThread.start()
except (KeyboardInterrupt, SystemExit):
    recieveThread.join()
    client.close()
    writingThread.join()
    sys.exit()
