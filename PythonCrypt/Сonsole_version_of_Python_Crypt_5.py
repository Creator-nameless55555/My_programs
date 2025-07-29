import os, sys
print('Welcome to the console version of Python Crypt')
a=input("Select an action (1-Encrypt directory) (2-Decrypt directory) (3-About Python Crypt) (4-Exit the program): \n")
while 1!=0:
    if a=='1':
        i=str(input('Which directory to encrypt?\n'))
        def crypt(f):
            import pyAesCrypt
            print("---------------------------------------------------------------" )
            password="01"
            bufferSize = 512*1024
            pyAesCrypt.encryptFile(str(f), str(f)+".crp", password, bufferSize)
            print("[crypted] '"+str(f)+".crp'")
            os.remove(f)
        def walk(dir):
            for name in os.listdir(dir):
                path = os.path.join(dir, name)
                if os.path.isfile(path):
                    crypt(path)
                else:
                    walk(path)
        try:
            walk(i)
        except FileNotFoundError:#ловим ошибки
            print('The system cannot find the directory specified.')
        except NotADirectoryError:#ловим ошибки
            print('Invalid directory name')
        except OSError:#ловим ошибки
            print('Syntax error in file name, folder name, or volume label: ' +'"' + i + '"')
        print("---------------------------------------------------------------" )
        a=input("Select an action (1-Encrypt directory) (2-Decrypt directory) (3-About Python Crypt) (4-Exit the program): \n")
    elif a=='2':
        o=str(input('Which directory to decrypt?\n'))
        def decrypt(f):
            import pyAesCrypt
            print("---------------------------------------------------------------" )
            password="01"
            bufferSize = 512*1024
            pyAesCrypt.decryptFile(str(f), str(os.path.splitext(f)[0]), password, bufferSize)
            print("[decrypted] '"+str(os.path.splitext(f)[0])+"'")
            os.remove(f)
        def walk(dir):
            for name in os.listdir(dir):
                path = os.path.join(dir, name)
                if os.path.isfile(path):
                    try: decrypt(path)
                    except: pass
                else: walk(path)
        try:
            walk(o)
        except FileNotFoundError:#ловим ошибки
           print('The system cannot find the directory specified.') 
        except NotADirectoryError:#ловим ошибки
            print('Invalid directory name')
        except OSError:#ловим ошибки
            print('Syntax error in file name, folder name, or volume label: ' +'"' + o + '"')
        print("---------------------------------------------------------------" )
        a=input("Select an action (1-Encrypt directory) (2-Decrypt directory) (3-About Python Crypt) (4-Exit the program): \n")
    elif a=='3':
        print('Author: Tural Salamov\nDate of creation: 05.27.2019\nVersion: 0.0.0.1')
        a=input("Select an action (1-Encrypt directory) (2-Decrypt directory) (3-About Python Crypt) (4-Exit the program): \n")
    else:
        break
