import tkinter
from tkinter.filedialog import asksaveasfile, askopenfile
from tkinter.messagebox import showinfo
 
FILE_NAME = "File.txt"

def new_file():
    global FILE_NAME
    FILE_NAME = "Untitled"
    text.delete('1.0', tkinter.END)
 
 
def save_file():
    data = text.get('1.0', tkinter.END)
    out = open(FILE_NAME, 'w')
    out.write(data)
    out.close()
 
 
def save_as():
    out = asksaveasfile(mode='w', defaultextension='.txt')
    data = text.get('1.0', tkinter.END)
    try:
        out.write(data.rstrip())
    except Exception:
        showinfo(title="Oops!", message="Unable to save file....")
 
 
def open_file():
    global FILE_NAME
    inp = askopenfile(mode="r")
    if inp is None:
        return
    FILE_NAME = inp.name
 
    data = inp.read()
    text.delete('1.0', tkinter.END)
    text.insert('1.0', data)

def make_menu(w):
    global the_menu
    the_menu = tkinter.Menu(w, tearoff=0)
    the_menu.add_command(label="Cut")
    the_menu.add_command(label="Copy")
    the_menu.add_command(label="Paste")

def show_menu(e):
    w = e.widget
    the_menu.entryconfigure("Cut",
    command=lambda: w.event_generate("<<Cut>>"))
    the_menu.entryconfigure("Copy",
    command=lambda: w.event_generate("<<Copy>>"))
    the_menu.entryconfigure("Paste",
    command=lambda: w.event_generate("<<Paste>>"))
    the_menu.tk.call("tk_popup", the_menu, e.x_root, e.y_root)
 
root = tkinter.Tk()
root.title("Notepad_Python_my")
'''root.minsize(width=100, height=500)
root.maxsize(width=500, height=500)'''
#для того, чтобы окно открывалось по середине=====
w = 590 # width for the Tk root
h = 600 # height for the Tk root
# get screen width and height
ws = root.winfo_screenwidth() # width of the screen
hs = root.winfo_screenheight() # height of the screen
# calculate x and y coordinates for the Tk root window
x = (ws/2) - (w/2)
y = (hs/2) - (h/2)
# set the dimensions of the screen 
# and where it is placed
root.geometry('%dx%d+%d+%d' % (w, h, x, y))
#============================

menuBar = tkinter.Menu(root)
fileMenu = tkinter.Menu(menuBar)
fileMenu.add_command(label="New", command=new_file)
fileMenu.add_command(label="Open", command=open_file)
fileMenu.add_command(label="Save", command=save_file)
fileMenu.add_command(label="Save As", command=save_as)
fileMenu.add_separator()
fileMenu.add_command(label="Exit", command=root.quit)
menuBar.add_cascade(label="File", menu=fileMenu)

text = tkinter.Text(root, width=900, height=900, bg = "black", fg = "white", insertbackground="white")
text.pack()

make_menu(root)
text.bind_class("Text", "<Button-3><ButtonRelease-3>", show_menu)

fileMenu2 = tkinter.Menu(menuBar)
fileMenu2.add_command(label="Light theme", command=lambda: text.config(bg = "white", fg = "black",insertbackground="black"))
fileMenu2.add_command(label="Dark theme", command=lambda: text.config(bg = "black", fg = "white",insertbackground="white"))
menuBar.add_cascade(label="Theme", menu=fileMenu2)

fileMenu5 = tkinter.Menu(menuBar)
fileMenu5.add_command(label="About the program", command=lambda: showinfo(title="About the program!", message="Author: Tural Salamov\nDate of creation: 20.08.2019\nVersion: 0.0.0.1'"))
menuBar.add_cascade(label="Help", menu=fileMenu5)

root.config(menu=menuBar)
root.mainloop()
