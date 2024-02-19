import serial
import requests

COM_PORT = "COM3"
BAUD_RATE = 9600
WEB_APP_URL = "<INSERT_AZURE_WEB_APP_URL>"

if __name__ == "__main__":
    serialManager = serial.Serial(COM_PORT, BAUD_RATE)
    while True:
        data = serialManager.readline().decode().strip()
        if data:
            requests.post(WEB_APP_URL, data=data)