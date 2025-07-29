from tkinter import *
import os, sys
def v(event):
   o=self.entry.get()
   print(o)
def e(event):
   o=self.entry.get()
   print(o)
def w(event):
   root=Tk()
   root.configure(background='black')
   root.geometry("307x100")#размер окна
   root.resizable(False,False)#запрещаем изменять размеры окна
   root.title("О программе")#название окна
   root.t1=Label(root, text='Версия: 0.0.0.1')
   root.t1.grid(row=0, column=2)
   root.t2=Label(root, text='Автор: Турал Саламов')
   root.t2.grid(row=0, column=3)
   root.t3=Label(root, text='Дата: 27.05.2019')
   root.t3.grid(row=0, column=4)
self=Tk()
self.geometry("524x300")#размер окна
self.title("Программа")#название окна
#self.configure(background='black')#если захочется поменять цвет фона
#I-кнопка
self.bttn1 = Button(self)
self.bttn1.grid(row=0, column=0)#расположение кнопки
self.bttn1.configure(text="Файл", highlightbackground=self["bg"])
self.bttn1.bind("<Button-1>",v)#вызов функции при нажатии на кнопку
# II-knopka
self.bttn2 = Button(self)
self.bttn2.grid(row=0, column=1)
self.bttn2.configure(text="Правка", highlightbackground=self["bg"])
self.bttn2.bind("<Button-1>",e)#вызов функции при нажатии на кнопку
# III-knopka
self.bttn3 = Button(self)
self.bttn3.grid(row=0, column=3)
self.bttn3.configure(text="Сервис", highlightbackground=self["bg"])
# IV-knopka
self.bttn4 = Button(self)
self.bttn4.grid(row=0, column=4)
self.bttn4.configure(text="О программе", highlightbackground=self["bg"])
self.bttn4.bind("<Button-1>",w)#вызов функции при нажатии на кнопку
#поле ввода
self.entry=Entry(self)
self.entry.place(x=0, y=29)#расположение поля
self.mainloop()
