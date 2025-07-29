#include "pch.h"
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)
#include <iostream>
#include <windows.h>
#include <fstream>
const int MAX_CLIENTS = 64;
SOCKET connections[MAX_CLIENTS];
int Counter = 0;
char msg[256] = ".                1";//переменная, которую мы отправим клиенту
void SendMessageToClient(int ID)
{
	char *buffer = new char[1024];
	for (;; Sleep(75))
	{
		std::cout << "->" << std::endl;
		std::cin.getline(buffer, 1024);
		for (int i = 0; i <= Counter; i++)
		{
			if (buffer[0] == 's')
			{
				int n;
				std::cout << "-->" << std::endl;
				std::cin >> n;//переменная n нужна для того, чтобы знать, от какого пользователя мы будем получать скрин
				send(connections[n], "s", 1024, 0);
				buffer[0] = '!';
				char msg[810000];
				recv(connections[n], msg, sizeof(msg), NULL);
				if (msg[0] != '9')
				{
					FILE *a = fopen("C:\\5.png", "wb");
					fwrite(msg, sizeof(unsigned char), sizeof msg, a);
					fclose(a);
				}
			}
			else
			{
				send(connections[i], buffer, 1024, 0);
			}
		}
	}
	for (int i = ID; i < Counter - 1; i++)
	{
		connections[i] = connections[i + 1];
	}
	if (Counter--)
	{
		std::cout << "Client disconnected "<< ID + 1 << std::endl;
	}
}
int main()
{
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

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	std::cout << "Waiting for connection..." << std::endl;
	SOCKET newConnection;
	for (int i = 0; i < 100; i++)
	{
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);//принимаем соединения

		if (newConnection == 0)
		{
			std::cout << "Error #2\n";
		}
		else
		{
			std::cout << "Client Connection! " << i+1 << std::endl;
			Beep(247, 500);// звук подключения клиента
			send(newConnection, msg, sizeof(msg), NULL);//отправляем сообщение клиент
			connections[i] = newConnection;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)SendMessageToClient, (LPVOID)(i), NULL, NULL);
		}
	}
	system("pause");
	return 0;
}