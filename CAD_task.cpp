#undef UNICODE
#include <windows.h>
#include <string>
#include "Rectangle.h"
#include "Circle.h"
#include "Oval.h"
#include "Square.h"
#include "Triangle.h"
#include "Render.h"

HINSTANCE hInstance;
HWND      hMainWindow;
HWND      hFigureCombo;
CRenderPtr spRenderObj = std::make_shared<CRender>();

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (CBN_SELCHANGE == HIWORD(wParam))
		{
			InvalidateRect(hMainWindow, NULL, true);
			int ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM) 0);
			TCHAR ListItem[256];
			SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem);
			CFigurePtr spFigureObj;
			std::string sFig(ListItem);
			if (sFig == "Квадрат")
				spFigureObj = std::make_shared<CSquare>();
			else if (sFig == "Прямоугольник")
				spFigureObj = std::make_shared<CRectangle>();
			else if (sFig == "Треугольник")
				spFigureObj = std::make_shared<CTriangle>();
			else if (sFig == "Круг")
				spFigureObj = std::make_shared<CCircle>();
			else if (sFig == "Овал")
				spFigureObj = std::make_shared<COval>();

			PAINTSTRUCT ps;
			HDC dc = BeginPaint(hMainWindow, &ps);
			spFigureObj->SetHDC(dc);
			spRenderObj->DrawFigure(spFigureObj);

			EndPaint(hMainWindow, &ps);
			ValidateRect(hMainWindow, NULL);

		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		UnregisterClass("window", hInstance);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void MyCreateWindow()
{
	WNDCLASS wnd; 
	memset(&wnd, 0, sizeof(WNDCLASS));

	wnd.lpfnWndProc = WindowProc;
	wnd.lpszClassName = "window";
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = CreateSolidBrush(0xEFEFEF);

	RegisterClass(&wnd);

	hMainWindow = CreateWindow("window", "window", WS_OVERLAPPEDWINDOW,
		200, 200, 1600, 900, 0, 0, hInstance, 0);

	CreateWindow("static", "Выберите фигуру для отрисовки",
		WS_CHILD | WS_VISIBLE,
		10, 30, 250, 500, hMainWindow, 0, hInstance, 0);

	hFigureCombo = CreateWindow("COMBOBOX", "combobox",
		WS_CHILD | WS_VISIBLE | CBS_SORT | CBS_DROPDOWNLIST,
		10, 50, 250, 500, hMainWindow, 0, hInstance, 0);

	SendMessage(hFigureCombo, CB_ADDSTRING, 0, (LPARAM)"Квадрат");
	SendMessage(hFigureCombo, CB_ADDSTRING, 0, (LPARAM)"Прямоугольник");
	SendMessage(hFigureCombo, CB_ADDSTRING, 0, (LPARAM)"Треугольник");
	SendMessage(hFigureCombo, CB_ADDSTRING, 0, (LPARAM)"Круг");
	SendMessage(hFigureCombo, CB_ADDSTRING, 0, (LPARAM)"Овал");

	ShowWindow(hMainWindow, SW_SHOW);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviuos, LPSTR lpCmdLine, int nCmdShow)
{
	::hInstance = hInstance;
	MyCreateWindow();
	while (true)
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}