#include "initialization.h"

std::string correct_activation_code="AAAAB3NzaC1yc2EAAAABIwAAAQEAq2A7hRGmdnm9tUDbO9IDSwBK6TbQa+PXYPCPy6rbTrTtw7PHkccKrpp0yVhp5HdEIcKr6pLlVDBfOLX9QUsyCOV0wzfjIJNlGEYsdlLJizHhbn2mUjvSAHQqZETYP81eFzLQNnPHt4EVVUh7VfDESU84KezmD5QlWpXLmvU31/yMf+Se8xhHTvKSCZIFImWwoG6mbUoWf9nzpIoaSjB+weqqUUmpaaasXVal72J+UX2B+2RPW3RcT0eOzQgqlJL3RKrTJvdsjE3JEAvGq3lGHSZXy28G3skua2SmVi/w4yCE6gbODqnTWlg7+wC604ydGXA8VJiS5ap43JXiUFFAaQ==";



int activation()
{

    std::fstream _file;
    _file.open("hots",std::ios::in);
    std::string activation_code;
    std::string invitation_code;
    if(!_file){
        _file.open("hots",std::ios::out);
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
            _file.open("hots",std::ios::out);
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
}

void windows_initialization(){
    SetTitle("noip_help");

}
