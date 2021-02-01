//
// Created by shexuan on 2021/1/30.
//
#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include <vector>
#include "computer_room.h"

#ifndef RESERVATION_SYSTEM_MANAGER_H
#define RESERVATION_SYSTEM_MANAGER_H


/* 管理员功能
 *  （1）显示管理员操作的菜单界面；
 *  （2）添加账号；
 *  （3）查看账号；
 *  （4）查看机房信息；
 *  （5）清空预约记录
 */

class Manager: public Identity{
public:
    // 默认构造函数
    Manager();

    // 有参构造函数
    Manager(string name, string pwd);

    // 显示管理员菜单
    void show_menu();

    // 初始化容器, 用于添加账号时检测去重
    void init_vector();

    // 检测账号是否重复，这里也可以写成一个模板类，第一个参数改为vector，其中vector中的类型即为传入的模板类型
    bool is_repeat(int id, int type);

    // 添加用户
    void add_user();

    // 查看账号
    void show_account();

    // 查看机房信息
    void show_compRoom();

    // 清空预约信息
    void clear_orders();

    // 析构
    ~Manager();

    // 学生容器
    vector<Student> v_stu;

    // 教师容器
    vector<Teacher> v_tea;

    // 机房信息容器
    vector<computerRoom> v_computer;
};


#endif //RESERVATION_SYSTEM_MANAGER_H
