import pygetwindow as gw
from arduinoControl import ArduinoController
import time

arduino = ArduinoController(port='COM3', baud=9600)

names = [
    "Khan Academy",
    "Coursera",
    "edX",
    "Quizlet",
    "WolframAlpha",
    "Overleaf",
    "Grammarly",
    "Notion",
    "Trello",
    "Google Drive",
    "Typing.com",
    "SparkNotes",
    "Chegg",
    "Pomofocus"
]

while True:
    active = gw.getActiveWindow()
    if active is None:
        time.sleep(0.5)
        continue

    if not any(active.title in item for item in names):
        arduino.turn_on()
        print("Google Docs not active → Arduino ON")
    else:
        arduino.turn_off()
        print("Google Docs active → Arduino OFF")

    time.sleep(0.5)