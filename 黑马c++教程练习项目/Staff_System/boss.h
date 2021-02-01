//
// Created by shexuan on 2021/1/12.
//

#pragma onece
#include <iostream>
#include <string>
#include "workers.h"

#ifndef STAFF_SYSTEM_BOSS_H
#define STAFF_SYSTEM_BOSS_H


class Boss: public Workers{
public:
    // 构造函数
    Boss(int id, string name, int dept_id);

    // 显示员工信息
    void show_info();

    // 获取岗位信息
    string getDeptName();

    ~Boss();
};


#endif //STAFF_SYSTEM_BOSS_H
