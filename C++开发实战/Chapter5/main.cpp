#include <iostream>
#include <string>

#include <fstream>
#include "atm.h"
using namespace std;

/* 模拟ATM机界面
 * 设计一个简单的模拟自动提款机ATM界面的程序，实现用户登录及取款等功能.
 * 主要功能（界面选项）包括：
 *  （1）输入正确密码进入主目录界面；
 *  （2）取款；
 *  （3）显示剩余金额；
 *  （4）退出系统界面
 */



int main() {
    ATM atm;

    bool valid = atm.validate_login();
    if (!valid){
        return 0;
    }

    while (true){
        atm.show_menu();
        cout << "请输入您的选择：";
        int select;
        cin >> select;

        switch (select){
            case 1:
                // 1、取款
                atm.withdrawl();
                break;
            case 2:
                // 2、显示余额
                atm.show_balance();
                break;
            default:
                cout << "欢迎再次光临！" << endl;
                cin.get();
                system("clear");
                return 0;
        }

    }
    return 0;
}