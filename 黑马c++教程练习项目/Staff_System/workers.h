//
// Created by shexuan on 2021/1/12.
//

#pragma onece
#include <iostream>
#include <string>

using namespace std;


#ifndef STAFF_SYSTEM_WORKERS_H
#define STAFF_SYSTEM_WORKERS_H

/* 职工分类：普通员工、经理、老板
 *
 * 将三种职工抽象到一个类中，利用多态实现不同的职工类
 * 职工属性: 职工编号，职工姓名，职工所在部门编号；
 * 职工行为: 岗位职责信息描述，获取岗位名称.
 *
 */


// 职工抽象类
class Workers {
public:
    // 显示职工信息
    virtual void show_info()=0;

    // 获取岗位名称
    virtual string getDeptName()=0;

    virtual ~Workers();

    int m_Id; // 职工编号
    string m_Name; // 职工姓名
    int m_DeptId; // 职工部门
};

#endif //STAFF_SYSTEM_WORKERS_H
