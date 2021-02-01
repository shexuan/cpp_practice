//
// Created by shexuan on 2021/1/12.
//
#pragma onece
#include <iostream>
#include <string>
#include "workers.h"
using namespace std;



#ifndef STAFF_SYSTEM_EMPLOYEE_H
#define STAFF_SYSTEM_EMPLOYEE_H

//
class Employee: public Workers {
public:
    // 构造函数
    Employee(int id, string name, int dept_id);

    // 显示个人信息
    void show_info();

    // 获取岗位信息
    string getDeptName();

    // 析构函数
    ~Employee();
};


#endif //STAFF_SYSTEM_EMPLOYEE_H
