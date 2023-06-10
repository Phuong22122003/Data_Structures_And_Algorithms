#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <fstream>
#include <cstring>

using namespace std;
//void gotoxy(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
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
/*
void Insert(Nodeptr&root, int x,int a)//x is key, a is info
{
    Nodeptr fb,p,q,
            fya,ya,//ya là nút gần nhất bị mất cân bằng
            s;//nut theo huong mat can bang
    int imbal;// imbal=1 lech trai||imbal=-1 lech phai
    fb=NULL; p=root;
    fya=NULL;ya=p;
    while(p!=NULL){
        if(x==p->key)return;
        if(x<p->key)q=p->left;
        else q=p->right;
        if(q!=NULL)
         if(q->bf!=0){// nut mat can bang
            fya=p;
            ya=q;
        }
        fb=p;// la nut cha cua nut can them
        p=q;
    }
    // them nut moi vao
    q=new nodetype;
    q->key=x;q->infor=a;q->bf=0;
    q->left=NULL;q->right=NULL;
    if(x<fb->key)fb->left=q;
    else fb->right=q;
    //hieu chinh chi so can bang cua tat cua cac nut tu
    // ya den q
    if(x<ya->key)
        p=ya->left;
    else 
        p=ya->right;
    s=p;//s la nut co chi so can bang
    while(p!=q)
    {
        if(x<p->key)
        {
            p->bf=1;
            p=p->left;
        }
        else 
        {
            p->bf=-1;
            p=p->right;
        }
    }
    if(x<ya->key)imbal=1;
    else imbal=-1;
    if(ya->bf==0)// truong hop them vao cay khong co bf!=0 can bang
    {
        ya->bf=imbal;
        return ;
    }
    if(ya->bf!=imbal)//truong hop them cay vao nhung van can bang
    {                  //do dua nut moi vao huong nguoc lai
        ya->bf=0;
        return ;
    }
    // cay mat can bang

    // bat dau xet truong hop
    if(s->bf==imbal)//xoay don
    {
        if(imbal==1)// cung lech trai hoac cung lech phai
            p=Rotate_right(ya);
        else 
            p=Rotate_left(ya);
        ya->bf=0;
        s->bf=0;
    }
    else
    {
        if(imbal==1)
        {
            ya->left=Rotate_left(s);
            p=Rotate_right(ya);
        }
        else
        {
            ya->right=Rotate_right(s);
            p=Rotate_left(ya);
        }

        // chinh lai bf
        if(p->bf==0)//truong hop p la nut moi them
        {
            ya->bf=0;
            s->bf=0;
        }
        else 
        {
            // truong hop 1b
           if(p->bf==imbal)
           {
            ya->bf=-imbal;
            s->bf=0;
           }
           else// truong hop 2b
           {
            ya->bf=0;
            s->bf=imbal;
           }
        }
        p->bf=0;
    }

    // nối lại 
    if(fya==NULL)// trường hợp nút gốc bị mất cân bằng
    root=p;
    else if(ya==fya->right)
    fya->right=p;
    else 
    fya->left=p;
}
*/

