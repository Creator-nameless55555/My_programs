import win32api
import time
while True:
    x, y = win32api.GetCursorPos()#получение координат курсора мышка
    print("["+str(x)+";"+str(y)+"]")#выводим на экран
    time.sleep(0.5)
input()
