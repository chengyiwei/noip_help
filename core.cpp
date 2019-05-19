#include "core.h"

void run(){
    windows_initialization();
    get_user_data();
    user_initialization();
    DeleteFile("user.tmp");
    get_user_data();
    main_menu();
}

void main_menu(){
    std::string week[]={"一","二","三","四","五","六","日"};
    std::string main_menu[]={"数据构造器","洛谷"};

    SetColorXY(1,show_windth-1,1,line-1,background_color);
    SetColorXY(1,show_windth-1,line+1,show_high-1,background_color);
    SetColor(main_color,background_color);SetPosition(40,1);printf("NOIP辅助器3.0 BY:CYW");
    SetColor(main_color,background_color);SetPosition(44,2);printf("衢州市兴华中学");
    tm* now_time=get_time();
    SetColor(main_color,background_color);SetPosition(34,3);printf("%d年%d月%d日 星期%s",1900+now_time->tm_year,1+now_time->tm_mon,now_time->tm_mday,week[now_time->tm_wday].c_str());
    SetColor(main_color,background_color);SetPosition(40,4);calculation_noip_time();
    SetColor(main_color,background_color);SetPosition(46,5);printf("主菜单");
    while(1){
        tm* now_time=get_time();
        SetColor(main_color,background_color);SetPosition(55,3);printf("%d时%d分%d秒",now_time->tm_hour,now_time->tm_min,now_time->tm_sec);
        if()
    }
}

void calculation_noip_time(){
    tm* now_time=get_time();
    if(now_time->tm_yday>311){
        printf("距离NOIP%d还有%d天",now_time->tm_year+1,(now_time->tm_yday+365)-311);
    }
    else {
        printf("距离NOIP%d还有%d天",now_time->tm_year,311-now_time->tm_yday);
    }
    return ;
}
