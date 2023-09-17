#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <fstream>
#include <cstring>

using namespace std;
class Mouse {
public:
    Mouse() {
        // Thi?t l?p ch? d? console input d? ch? nh?n s? ki?n chu?t
        HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD prevMode;
        GetConsoleMode(hConsoleInput, &prevMode);
        SetConsoleMode(hConsoleInput, prevMode | ENABLE_MOUSE_INPUT);
    }

    bool IsLeftButtonPressed() {
        return GetKeyState(VK_LBUTTON) < 0;
    }

    void GetCursorPosition(int& x, int& y) {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        ScreenToClient(GetConsoleWindow(), &cursorPos);
        x = cursorPos.x;
        y = cursorPos.y;
    }
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetConsoleFullScreen()
{
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
}
int main() {
	keybd_event(VK_F11, 0, 0, 0); // Simulate pressing F11 key
    //keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0); // Simulate releasing F11 key
    int x,y;
    Mouse a;
    gotoxy(10,10);cout<<"|";
    while(1)
	{
		a.GetCursorPosition(x,y);
		if(a.IsLeftButtonPressed())
		{
			gotoxy(0,0);cout<<x<<" "<<y;
			Sleep(1000);
		}
	}
    return 0;
}
