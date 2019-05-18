#include "lib.h"

/* 设置控制台窗口标题 */
void SetTitle(char * title){
    SetConsoleTitle(title);
}

/*快速清屏*/
void Clrscr() {
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen= {0,0};
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	dwConSize=csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole,&csbi);
	FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
	SetConsoleCursorPosition(hConsole,coordScreen);
	return;
}

void HideCursor(int n) /*隐藏光标*/
{
    CONSOLE_CURSOR_INFO cursor_info={1,n};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
} //n default 0

/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色*/
void SetColor(int ForeColor, int BackGroundColor){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //获取当前窗口句柄
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
    //CloseHandle(handle);
}

/* 根据宽高设置控制台窗口的大小 */
void SetConsoleWindowSize(const int &WIN_SIZE_WIDTH,const int &WIN_SIZE_HEIGHT){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置控制台窗口的缓冲区大小
	COORD size = {WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT};
	SetConsoleScreenBufferSize(handle, size);
	//设置控制台窗口大小,最大坐标是缓冲区大小-1
	SMALL_RECT rect = {0, 0, WIN_SIZE_WIDTH - 1, WIN_SIZE_HEIGHT - 1};
	SetConsoleWindowInfo(handle, 1, &rect);
	//CloseHandle(handle);
}

/* 改变光标位置 */
void SetPosition(int x, int y){
    COORD cursorPosition;   //光标的坐标
    HANDLE handle;          //当前窗口句柄
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //设置x、y坐标
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
    //CloseHandle(handle);
}

/* 间隔输出 */
void PrintString(const char * msgString,const int &data=0){
    int length = strlen(msgString);
    int i = 0;
    for(; i < length; i++)
    {
        char tempChar = msgString[i];
        putchar(tempChar);
        Sleep(data);//毫秒
        fflush(stdout);
    }
}

/* 把一个区间内的颜色刷成color */
void SetColorXY(const int& Le_x,const int& Ri_x,const int& Up_y,const int& Dn_y,const int& Color){
	SetColor(Color,Color);
	for(int i=Up_y;i<=Dn_y;i++){
		SetPosition(Le_x,i);
		for(int j=Le_x;j<=Ri_x;j++)putchar(' ');
	}
	return ;
}

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

tm* get_time(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return ltm;
}
