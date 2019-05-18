#include "core.h"

void run(){
    windows_initialization();
    get_user_data();
    user_initialization();
    main_menu();
}

void main_menu(){
    SetColorXY(1,show_windth-1,1,line-1,background_color);
    SetColorXY(1,show_windth-1,line+1,show_high-1,background_color);
    SetColor(main_color,background_color);SetPosition(40,1);printf("NOIP辅助器3.0 BY:CYW");
    SetColor(main_color,background_color);SetPosition(44,2);printf("衢州市兴华中学");
    SetColor(main_color,background_color);SetPosition(46,3);printf("主菜单");
    tm* now_time=get_time();
    SetColor(main_color,background_color);SetPosition(37,4);printf("%d年%d月%d日",1900+now_time->tm_year,1+now_time->tm_mon,now_time->tm_mday);
    while(1){
        tm* now_time=get_time();
        SetColor(main_color,background_color);SetPosition(51,4);printf("%d时%d分%d秒",now_time->tm_hour,now_time->tm_min,now_time->tm_sec);
    }
}
