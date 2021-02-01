#pragma onece
#include <iostream>
#include <string>
#include "WorkerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;


/* 职工管理系统
 *
 * 管理系统需求
 * 职工管理系统可以用来管理公司内所有员工的信息，此处用C++来实现一个基于多态的员工管理系统。
 *
 * 公司职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位以及职责。
 *  - 普通员工职责：完成经理交给的任务；
 *  - 经理职责：完成老板交给的任务；
 *  - 老板职责：管理公司所有事物。
 *
 * 管理系统中需要实现的功能如下：
 *  - 退出管理程序：退出当前管理系统；
 *  - 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号；
 *  - 显示职工信息：显示公司内部所有职工信息；
 *  - 删除离职职工：按编号删除指定的职工；
 *  - 修改职工信息：按照编号修改职工信息；
 *  - 查找职工信息：按照编号或职工姓名进行查找相关的人员信息；
 *  - 按照编号排序：按照职工编号进行排序，排序规则由用户指定；
 *  - 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）。
 *
 *
 * 1、创建管理类
 * 管理类负责的内容如下：
 *  - 与用户的交互菜单界面；
 *  - 对职工进行增删查改操作；
 *  - 与文件的交互读写
 *
 * 如果想将所有不同种类的员工放到一个数组中，可以将所有员工的指针维护到一个数组里。
 * 如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker **的指针维护。
 * Wokers* *wokers = new Workers*[5];
 * 注：前面的Workers*表示数组中储存的元素是Workers*类型，由于使用了new开辟空间，因此返回值为地址需要用指针接收，
 *   所以后面是*workers.
 */

int main1(){
    Workers * worker = NULL;
    // 测试普通员工类
    worker = new Employee(1, "张三", 3);
    worker->show_info();
    // cout << &worker << endl;
    // cout << *(&worker) << endl;
    // string wname = worker->getDeptName();

    // cout << wname << endl;
    delete worker;

    // 测试经理类
    // Workers * worker2;
    worker = new Manager(2, "李四", 2);
    worker->show_info();
    delete worker;
    // cout << &worker << endl;
    // cout << *(&worker) << endl;

    // 测试boss类
    // Workers * worker3;
    worker = new Boss(3, "王五", 1);
    worker->show_info();
    delete worker;
    // cout << &worker << endl;
    // cout << *(&worker) << endl;
    delete worker;
    cout << "hello world" << endl;
    cout << &worker << endl;
}



int main() {
    // 实例化管理者对象类
    WorkerManager wm;

    // 显示菜单
    // wm.show_menu();
//    int choice;
//    cout << "请输入您的选择：" ;
//    cin >> choice;

    while (true){
        // 显示菜单
        wm.show_menu();
        int choice;
        cout << "请输入您的选择：" ;
        cin >> choice;

        switch (choice){
            case 0: // 退出系统
                wm.exitSystem();
                break;
            case 1: // 增加职工信息
                wm.add_emp();
                break;
            case 2: // 显示职工信息
                wm.show_Emp();
                break;
            case 3: // 删除离职职工
                wm.del_Emp();
                break;
            case 4: // 修改职工信息
                wm.modify_Emp();
                break;
            case 5: // 查找职工信息
                wm.find_Emp();
                break;
            case 6: // 按照编号排序
                wm.sort_Id();
                break;
            case 7: // 清空所有文档
                wm.clear_file();
                break;
            default:
                break;
        }

    }

    return 0;
}
















