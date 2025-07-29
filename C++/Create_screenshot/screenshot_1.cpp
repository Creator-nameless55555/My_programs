#include "pch.h"
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "GdiPlus.lib") 
using namespace Gdiplus; 

static const GUID png =
{ 0x557cf406, 0x1a04, 0x11d3, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };

void screen()
{
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
	// Скриншот сделан
	BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)SelectObject(memdc, membit);
	Gdiplus::Bitmap bitmap(hBitmap, NULL);
	bitmap.Save(L"screen.png", &png);
	DeleteObject(hBitmap);
	//GdiplusShutdown(gdiplusToken);
}
int main()
{
	screen();
}