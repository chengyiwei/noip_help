#include <iostream>
#include <thread>
#include <cstdio>
#include <windows.h>
#include <ctime> ,
#include<conio.h>


using namespace std;
int f=-1;
/* 获取键盘按键 */
int GetKey()
{
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Read;
    INPUT_RECORD Event;
    //得到控制台的输入
    ReadConsoleInput(handle, &Event, 1, &Read);
    //如果输入事件是一个键盘事件，就进行判断，返回按下键的虚拟键码
    if(Event.EventType == KEY_EVENT)
    {
        if(Event.Event.KeyEvent.bKeyDown)//返回值为true，表示有键被按下
        {
             return Event.Event.KeyEvent.wVirtualKeyCode;//返回按下键的虚拟键码
        }
    }
    return 0;
}
void p(){
    while(1){
        if(f==1)
            printf("1");
        else
            printf("0");
    }
}
int main()
{
    thread t(p);
    t.detach();
    t.~thread();
    while(1){
        getchar();
        f=-f;
    }
    Sleep(100);
    return  0;
}
