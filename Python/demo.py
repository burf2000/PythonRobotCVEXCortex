import serial
import time
import struct

ser = serial.Serial(port='/dev/tty.HC-05-DevB', baudrate=57600)
print("connected to: " + ser.portstr)


sendString = "Test data"
a = 0;

while True:
    
    ser.write(sendString.encode())
    print("Sent data")

    a += 1
    sendString = "Test data " + str(a)  
     
    time.sleep (0.1)
    
    result = ser.readline()
    print("> " + result) 
 
ser.close()
print("close")
