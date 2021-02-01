//
// Created by shexuan on 2021/1/30.
//
#pragma once

#include <string>
#include <iostream>
#include "identity.h"
using namespace std;

#ifndef RESERVATION_SYSTEM_TEACHER_H
#define RESERVATION_SYSTEM_TEACHER_H


/* 教师功能
 *  （1）显示教师菜单；
 *  （2）查看所有预约：查看全部预约信息以及预约状态；
 *  （3）审核预约：对学生的预约进行审核；
 */

class Teacher: public Identity {
public:
    // 默认构造函数
    Teacher();

    // 有参构造
    Teacher(int id, string name, string pwd);

    // 显示菜单栏
    void show_menu();

    // 查看所有预约，这里还可以进一步划分 已审核和待审核的预约信息
    void show_orders();

    // 审核预约
    void valid_order();

    // 教师编号
    int m_id;

};


#endif //RESERVATION_SYSTEM_TEACHER_H
