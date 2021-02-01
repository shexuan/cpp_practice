//
// Created by shexuan on 2021/1/12.
//

//#ifndef STAFF_SYSTEM_WORKERMANAGER_H
//#define STAFF_SYSTEM_WORKERMANAGER_H

#pragma once  // 防止头文件重复包含
#include <iostream>
#include <string>
#include <fstream>
#include "workers.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

#define FILENAME "empFile.txt"



/*
* 管理系统中需要实现的功能如下：
*  - 退出管理程序：退出当前管理系统；
*  - 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号；
*  - 显示职工信息：显示公司内部所有职工信息；
*  - 删除离职职工：按编号删除指定的职工；
*  - 修改职工信息：按照编号修改职工信息；
*  - 查找职工信息：按照编号或职工姓名进行查找相关的人员信息；
*  - 按照编号排序：按照职工编号进行排序，排序规则由用户指定；
*  - 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）。
*/


class WorkerManager {
public:
    // 构造函数
    WorkerManager();

    // 显示菜单
    void show_menu();

    // 退出系统
    void exitSystem();

    // 增加员工
    void add_emp();

    // 保存文件
    void save();

    // 判断文件是否存在
    bool m_FileIsEmpty;

    // 利用文件中记录的信息初始化员工
    void init_Emp();

    // 统计文件中记录职工的数量
    int get_EmpNum();

    int m_EmpNum; // 记录职工人数
    Workers ** m_EmpArray;

    // 显示职工
    void show_Emp();

    // 判断职工是否存在
    int isExist(int id);

    // 删除职工
    void del_Emp();

    // 修改职工信息
    void modify_Emp();

    // 查找职工
    void find_Emp();

    // 按职工编号进行排序
    void sort_Id();

    // 清空文件
    void clear_file();

    // 析构函数
    ~WorkerManager();
};


//#endif //STAFF_SYSTEM_WORKERMANAGER_H
