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
