import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

time.sleep(2)  # allow STM32 reset

t = time.strftime("%H:%M:%S")
ser.write((t + "\n").encode())

print("Sent:", t)

ser.close()
