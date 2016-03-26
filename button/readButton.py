import time
from RPi import GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setup(0, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
while True:
	inputval = GPIO.input(0)
	print inputval
	time.sleep(1)