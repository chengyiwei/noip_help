#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

/* 设置控制台窗口标题 */
void SetTitle(char *);

/* 快速清屏 */
void Clrscr();

/* 隐藏光标 */
void HideCursor(int);



/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
 * 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色*/
void SetColor(int , int );


/* 根据宽高设置控制台窗口的大小 */
void SetConsoleWindowSize(const int &,const int &);

/* 改变光标位置 */
void SetPosition(int , int );

/* 间隔输出 */
void PrintString(const char *,const int &);

/* 把一个区间内的颜色刷成color */
void SetColorXY(const int& ,const int& ,const int& ,const int& ,const int& );

/* 获取键盘按键 */
int GetKey();
#endif // LIB_H_INCLUDED
