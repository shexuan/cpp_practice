#pragma once
#include <iostream>
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "identity.h"
#include "fstream"
#include "order_file.h"
using namespace std;



/* 机房预约系统
 * 需求：设计一套机房计算机预约系统用以预约使用计算机.
 *
 * 1、系统用户
 * 分别有三种身份使用该系统：
 *  -（1）学生：预约申请使用机房；
 *  -（2）老师：审核学生预约；
 *  -（3）管理员：给学生、老师创建账号；
 *
 * 2、机房简介
 * 共有三间机房：
 *  -（1）1号机房，最大容量200人；
 *  -（2）2号机房，最大容量50人；
 *  -（3）3号机房，最大容量100人；
 *
 * 3、申请简介
 *  -（1）预约申请每周由管理员进行清空；
 *  -（2）学生只能预约未来一周的机房使用，预约日期为周一至周五，时段可选择上午和下午；
 *  -（3）教师来审核预约，依据实际情况审核预约通过与否；
 *
 * 4、系统具体需求
 *  -（1）进入登录界面，选项有登录和退出，可选登录身份有：学生、老师和管理员；
 *  -（2）每个身份登录都需要验证后才能进入子菜单：
 *      - 学生需要输入：学号、姓名、登录密码；
 *      - 老师需要输入：职工号、姓名、登录密码；
 *      - 管理员需要输入：管理员姓名、登录密码；
 *  -（3）学生具体功能：
 *      - 申请预约：预约机房；
 *      - 查看自身的预约：查看自己的预约状态；
 *      - 查看所有的预约：查看全部预约信息及预约状态；
 *      - 取消预约：取消自身的预约（预约成功或审核中的预约均可取消）；
 *      - 注销登录：退出登录；
 *  -（4）教师具体功能：
 *      - 查看所有预约：查看全部预约信息以及预约状态；
 *      - 审核预约：对学生的预约进行审核；
 *      - 注销登录：退出登录；
 *  -（5）管理员具体功能：
 *      - 添加账号：添加学生或教师账号，需检测学生编号或教师职工编号是否重复；
 *      - 查看账号：可以选择查看学生或者教师的全部信息；
 *      - 查看机房：查看机房的全部信息；
 *      - 清空预约：清空所有预约记录；
 *      - 注销登录：退出登录；
 *
 */


// 进入管理员子菜单
void manager_menu(Identity * &manager){
    while(true){
        // 显示子菜单，纯虚函数，父类指向子类
        manager->show_menu();

        // 将父类指针转为子类指针，调用子类里其它接口, 不然抽象父类只能调用子类重写实现的虚函数
        Manager * man = (Manager *) manager;

        int select=0;
        // 接受用户选项
        cin >> select;
        if (select==1){
            // 添加账号
            cout << "添加账号" << endl;
            man->add_user();
        }else if(select==2){
            // 查看账号
            cout << "查看账号" << endl;
            man->show_account();
        }else if(select==3){
            // 查看机房信息
            cout << "查看机房信息" << endl;
            man->show_compRoom();
        }else if(select==4){
            // 清空预约
            cout << "清空预约" << endl;
            man->clear_orders();
        }else{
            delete manager; // 销毁堆区对象
            cout << "注销成功" << endl;
            cin.get();
            system("clear");
            return;
        }

    }
}

// 学生子菜单
void student_menu(Identity * student){
    while (true){
        // 显示学生菜单，纯虚函数，父类指向子类
        student->show_menu();
        // 将父类指针转为子类指针，调用子类里其它接口, 不然抽象父类只能调用子类重写实现的虚函数
        Student* stu = (Student *) student;
        cout << "请输入您的选择：";
        int select;
        cin >> select;
        if (select==1){ // 申请预约
            stu->apply_order();
        }else if(select==2){ // 查看自身预约
            stu->show_myOrder();
        }else if(select==3){
            stu->show_allOrder();
        }else if(select==4){ // 取消预约
            stu->cancel_order();
        }else{
            cout << "注销成功！" << endl;
            break;
        }
    }

    delete student;
    cin.get();
    system("clear");
}

// 教师子菜单
void teacher_menu(Identity * teacher){
    while (true){
        // 显示教师菜单，纯虚函数，父类指向子类
        teacher->show_menu();
        // 将父类指针转为子类指针，调用子类里其它接口, 不然抽象父类只能调用子类重写实现的虚函数
        auto tea = (Teacher *) teacher;

        cout << "请输入您的选择：";
        int select;
        cin >> select;
        if(select==1){ // 查看所有预约
            tea->show_orders();
        } else if(select==2){ // 审核预约
            tea->valid_order();
        }else{
            delete teacher;
            cin.get();
            system("clear");
            break;
        }
    }
}



// 登录函数：根据用户的选择，以不同的身份登录
void Login(string filename, int type){
    ifstream ifs;
    ifs.open(filename, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在!" << endl;
        return;
    }

    Identity * person;
    int id=0;
    string name;
    string pwd;

    // 判断身份
    if (type==1){  // 学生
        cout << "请输入您的学号：" << endl;
        cin >> id;
    }else if(type==2){  // 老师
        cout << "请输入您的职工编号：" << endl;
        cin >> id;
    }

    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;
    int fId;  // 从文件中读取的id
    string fName, fPwd;  // 从文件中读取的用户名和密码
    if(type==1){ // 学生验证
        // 输入信息与文件中保存信息进行对比，一致则验证通过
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
            if(fId==id && fName==name && fPwd==pwd){
                cout << "学生验证登录成功！" << endl;
                cin.get();
                system("clear");
                person = new Student(id, name, pwd);
                // 进入到学生身份子菜单
                student_menu(person);
                return;
            }
        }
    }else if(type==2){  // 教师验证
        while(ifs>>fId && ifs>>fName && ifs>>fPwd) {
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "教师验证登录成功！" << endl;
                cin.get();
                system("clear");
                person = new Teacher(id, name, pwd);
                // 进入到教师身份子菜单
                teacher_menu(person);
                return;
            }
        }
    }else if(type==3){ // 管理员验证
        while(ifs>>fName && ifs>>fPwd) {
            if (fName == name && fPwd == pwd) {
                cout << "管理员证登录成功！" << endl;
                cin.get();
                system("clear");
                person = new Manager(name, pwd);
                // 进入到管理员身份子菜单
                manager_menu(person);
                return;
            }
        }
    }

    cout << "验证登录失败！" << endl;
    cin.get();
    system("clear");
}


int main() {
    OrderFile orderf;
    while (true) {
        cout << "====== 欢迎登录xx大学机房预约系统 ======" << endl;
        cout << "           * 1. 学生登录  *             " << endl;
        cout << "           * 2. 教师登录  *           " << endl;
        cout << "           * 3. 管理登录  *           " << endl;
        cout << "           * 0. 退出登录  *            " << endl;
        cout << "====================================" << endl;
        cout << "请输入您的选择：";
        int select;
        cin >> select;

        switch (select){
            case 0:
                // 退出登录
                cout << "欢迎再次使用！" << endl;
                cin.get();
                system("clear");
                return 0;
                break;
            case 1:
                // 学生登录
                Login("/Users/shexuan/BlackHorseCpp/Reservation_System/student.txt", 1);
                break;
            case 2:
                // 教师登录
                Login("/Users/shexuan/BlackHorseCpp/Reservation_System/teacher.txt", 2);
                break;
            case 3:
                // 管理员登录
                Login("/Users/shexuan/BlackHorseCpp/Reservation_System/admin.txt", 3);
                break;
            default:
                cout << "输入选项不存在，返回上一层." << endl;
                break;
        }
    }


}







//while (true){
//cin >> interval;
//if(interval==1 || interval==2){
//break;
//}else{
//cout << "时间段输入有误，请重新输入！" << endl;
//}
//}












