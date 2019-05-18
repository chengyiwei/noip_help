/*******************************************************
* 文件名: initialization.h
* 描  述: noip_help的初始化程序
* 日  期: 2019-4-21
* 官方QQ: 1485868106
* 版  权: (c) 2019 xinghua middle school CYW。保留所有权利。
********************************************************/
#ifndef INITIALIZATION_H_INCLUDED
#define INITIALIZATION_H_INCLUDED
#include <fstream>
#include <iostream>
#include "lib.h"
#include "init.h"

extern int selected_background_color;
extern int selected_main_color;
extern int background_color;
extern int main_color;
extern std::string name;

extern const int window_high;
extern const int window_width;
extern const int show_high;
extern const int show_windth;
extern const int line;


int activation();
void windows_initialization();
void get_user_data();
void user_initialization();
void __end();
#endif // INITIALIZATION_H_INCLUDED
