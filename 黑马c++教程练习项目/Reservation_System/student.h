//
// Created by shexuan on 2021/1/30.
//
#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "globalFile.h"
#include "identity.h"
#include "computer_room.h"
#include <vector>

#ifndef RESERVATION_SYSTEM_STUDENT_H
#define RESERVATION_SYSTEM_STUDENT_H


/* 学生类主要功能：
 *  （1）显示学生菜单；
 *  （2）申请预约；
 *  （3）查看自己的预约；
 *  （4）查看所有人的预测；
 *  （5）取消预约；
 */

class Student: public Identity {
public:
    // 默认构造
    Student();

    // 有参构造
    Student(int id, string name, string pwd);

    // 显示学生菜单
    void show_menu();

    // 申请预约，其实这里应该有个检查预约是否冲突等功能
    void apply_order();

    // 查看自己的预约
    void show_myOrder();

    // 查看所有人的预约
    void show_allOrder();

    // 取消预约
    void cancel_order();

    // 学生学号
    int m_id;

    // 机房信息容器
    vector<computerRoom> v_comp;
};


#endif //RESERVATION_SYSTEM_STUDENT_H
