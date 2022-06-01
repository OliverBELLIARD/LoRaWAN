# Get ip commands linux: nmap
# Get ip scan linux: nmap -sP 192.168.0.0/24
# Connect through SSH linux command (now done in FileZilla): ssh pi@192.168.0.254
# Shut down: sudo shutdown -h now
# FLASK_APP=serialTest_API.py flask run --host 0.0.0.0
# FLASK_APP=serialTest_API.py flask run
# nano serialTest_API.py

import serial
import time

ser = serial.Serial('/dev/serial0',9600)  # open serial port
print(ser.name)         # check which port was really used

ser.write(b"AT+RESET\r\n")
time.sleep(1)
ser.write(b"AT+LOG=DEBUG\r\n")
time.sleep(1)
ser.write(b"AT+MODE=TEST\r\n")
time.sleep(1)
ser.write(b"AT_TEST_TX1 \"AT+TEST=TXLRPKT, \"message from rpi\"\r\n")
time.sleep(1)
ser.write(b"AT+TEST=TXLRSTR, \"message from rpi\"\r\n")
time.sleep(1)

#while(1):
#	ser.write(b"Hello")     # write a string
#	time.sleep(0.01)
ser.close()             # close port
