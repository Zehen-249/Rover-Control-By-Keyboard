import socket
import serial

arduino_port = 'COM3'  # Replace with the appropriate port name
baud_rate = 9600  # Set the baud rate for the Arduino communication
arduino = serial.Serial(arduino_port, baud_rate)


HOST = '192.168.3.21'  # same rakhna dono laptop pe, vary only if needed
#setting
#network
#advanced network
#adapter
#properties
#tcp-ip4
#192.168.4.55 ip address # set different ip that is 192.168.4.52 client side hai yeh
#192.168.4.0  # set same gateway in client laptop


PORT = 4444  # The same port number used in the sending laptop  # never less that 1024
print("Host IP Address: ",HOST,"\nPORT: ",PORT)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((HOST, PORT))
sock.listen(1)
conn, addr = sock.accept()
#
# arduino_port = 'COM5'  # Replace with the appropriate port name
# baud_rate = 9600  # Set the baud rate for the Arduino communication
# arduino = serial.Serial(arduino_port, baud_rate)

print('Connected by', addr)
while True:
    data = conn.recv(1024).decode()
    if not data:
        print("System Stopped!!")
        break
    # print(data.decode())
    arduino.write(data.encode())
    # print(arduino.read().decode())
conn.close()
