import keyboard as kb
import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('192.168.3.21', 4444))  #the IP address of the receiving laptop #1024

def read_arrow_key():
    while True:
        event = kb.read_event()
        if event.event_type == 'down':
            if event.name == 'left':
                send_arrow_key('a')
            elif event.name == 'right':
                send_arrow_key('d')
            elif event.name == 'down':
                send_arrow_key('s')
            elif event.name == 'up':
                send_arrow_key('w')
            elif event.name == 'b':
                send_arrow_key('b')
            elif event.name == 'i':
                send_arrow_key('i')
            elif event.name == 'r':
                send_arrow_key('r')
            elif event.name == 't':
                send_arrow_key('t')
            elif event.name == 'f':
                send_arrow_key('f')
            elif event.name == 'g':
                send_arrow_key('g')
            elif event.name == 'j':
                send_arrow_key('j')
            elif event.name == 'h':
                send_arrow_key('h')
            elif event.name == 'z':
                send_arrow_key('z')
            elif event.name == 'o':
                send_arrow_key('o')
            elif event.name == 'u':
                send_arrow_key('u')
            elif event.name == 'm':
                send_arrow_key('m')
            elif event.name == 'l':
                send_arrow_key('l')
            elif event.name == 'q':
                send_arrow_key('q')



        elif event.event_type == 'up':
                send_arrow_key(' ')


def send_arrow_key(key):
    sock.send(key.encode())
    # if key == 'w':
    #     print('Upward')
    # elif key == 's':
    #     print('Downward')
    # elif key == 'a':
    #     print('Leftward')
    # elif key=='d':
    #     print('Rightward')


read_arrow_key()
