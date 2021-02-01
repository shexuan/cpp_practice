//
// Created by shexuan on 2021/1/12.
//

#pragma onece
#include <iostream>
#include <string>
#include "workers.h"

using namespace std;

#ifndef STAFF_SYSTEM_MANAGER_H
#define STAFF_SYSTEM_MANAGER_H


class Manager: public Workers {
public:
    // 构造函数
    Manager(int id, string name, int dept_id);

    // 显示函数
    void show_info();

    // 获取岗位信息
    string getDeptName();

    ~Manager();
};


#endif //STAFF_SYSTEM_MANAGER_H
