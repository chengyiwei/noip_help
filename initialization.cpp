#include "initialization.h"

const std::string correct_activation_code="AAAAB3NzaC1yc2EAAAABIwAAAQEAq2A7hRGmdnm9tUDbO9IDSwBK6TbQa+PXYPCPy6rbTrTtw7PHkccKrpp0yVhp5HdEIcKr6pLlVDBfOLX9QUsyCOV0wzfjIJNlGEYsdlLJizHhbn2mUjvSAHQqZETYP81eFzLQNnPHt4EVVUh7VfDESU84KezmD5QlWpXLmvU31/yMf+Se8xhHTvKSCZIFImWwoG6mbUoWf9nzpIoaSjB+weqqUUmpaaasXVal72J+UX2B+2RPW3RcT0eOzQgqlJL3RKrTJvdsjE3JEAvGq3lGHSZXy28G3skua2SmVi/w4yCE6gbODqnTWlg7+wC604ydGXA8VJiS5ap43JXiUFFAaQ==";
const char tilte[]="noip_help    by:cyw";
const int window_high=40;
const int window_width=120;
const int show_high=35;
const int show_windth=100;
const int line=7;

int background_color=0;
int main_color=10;
int selected_background_color=15;
int selected_main_color=12;
std::string name="C++";

int activation()
{

    std::fstream _file;
    _file.open("hots.tmp",std::ios::in);
    std::string activation_code;
    std::string invitation_code;
    if(!_file){
        _file.open("hots.tmp",std::ios::out);
        PrintString("请输入邀请码:",0);
        std::cin>>invitation_code;
        if(invitation_code==(std::string)"ZS"||invitation_code==(std::string)"zs")
            _file<<correct_activation_code;
        else {
                return 0;
        }
        return 1;
    }
    else{
        _file>>activation_code;
        if(activation_code==correct_activation_code){
            std::cout<<"激活成功"<<std::endl;
            return 1;
        }
        else {
            _file.open("hots.tmp",std::ios::out);
            PrintString("请输入邀请码:",0);
            std::cin>>invitation_code;
            if(invitation_code==(std::string)"ZS"||invitation_code==(std::string)"zs")
                _file<<correct_activation_code;
            else {
                return 0;
            }
            return 1;
        }
    }
    _file.close();
}

void windows_initialization(){
    SetTitle("noip_help       by:CYW");
    SetConsoleWindowSize(window_width,window_high);
    HideCursor(0);
}

void get_user_data(){
    std::fstream _file;
    _file.open("user.tmp",std::ios::in);
    if(!_file){
        _file.open("user.tmp",std::ios::out);
        _file<<"name"<<" "<<name<<std::endl;
        _file<<"background_color"<<" "<<background_color<<std::endl;
        _file<<"main_color"<<" "<<main_color<<std::endl;
        _file<<"selected_background_color"<<" "<<selected_background_color<<std::endl;
        _file<<"selected_main_color"<<" "<<selected_main_color<<std::endl;
    }
    else {
        std::string ptr;
        while(_file>>ptr){
            if(ptr=="name"){
                _file>>name;
            }
            else if(ptr=="background_color"){
                _file>>background_color;
            }
            else if(ptr=="main_color"){
                _file>>main_color;
            }
            else if(ptr=="selected_background_color"){
                _file>>selected_background_color;
            }
            else if(ptr=="selected_main_color"){
                _file>>selected_main_color;
            }
        }
    }
    _file.close();
    return ;
}

void user_initialization(){
    SetColor(main_color,background_color);
    SetPosition(1,0);for(int i=1;i<show_windth;i++)putchar('-');
    SetPosition(1,line);for(int i=1;i<show_windth;i++)putchar('-');
    SetPosition(1,show_high);for(int i=1;i<show_windth;i++)putchar('-');
    for(int i=1;i<show_high;i++){SetPosition(0,i);putchar('|');}
    for(int i=1;i<show_high;i++){SetPosition(show_windth,i);putchar('|');}
    SetPosition(0,0);printf("+");SetPosition(0,line);printf("+");SetPosition(0,show_high);printf("+");
    SetPosition(show_windth,0);printf("+");SetPosition(show_windth,line);printf("+");SetPosition(show_windth,show_high);printf("+");
}
