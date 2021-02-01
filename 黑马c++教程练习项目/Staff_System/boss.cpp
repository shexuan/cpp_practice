//
// Created by shexuan on 2021/1/12.
//

#pragma onece
#include <iostream>
#include <string>
#include "boss.h"
#include "workers.h"

using namespace std;

// 定义构造函数
Boss::Boss(int id, string name, int dept_id){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dept_id;
};

// 定义显示函数
void Boss::show_info() {
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t职工岗位：" << this->getDeptName()
         << "\t岗位职责：管理全部事务"
         << endl;
}

string Boss::getDeptName() {
    return string("老板");
}

Boss::~Boss() {}