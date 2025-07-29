import win32api
import win32con
import time
#имитация нажатия клавиши. Программа каждые 5 сек нажимает КАПСЛОК.
while True:
	print ("Caps Locking...", time.asctime())
	win32api.keybd_event(win32con.VK_CAPITAL,0,0,0)
	win32api.keybd_event(win32con.VK_CAPITAL,0,win32con.KEYEVENTF_KEYUP,0)
	time.sleep(5)
    
