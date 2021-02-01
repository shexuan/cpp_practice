//
// Created by shexuan on 2021/1/12.
//
#pragma onece
#include <iostream>
#include <string>
#include "employee.h"

using namespace std;

Employee::Employee(int id, string name, int dept_id) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dept_id;
}

void Employee::show_info() {
    cout << "职工编号：" << this->m_Id
        << "\t职工姓名：" << this->m_Name
        << "\t职工岗位：" << this->getDeptName()
        << "\t岗位职责：完成经理交给的任务"
        << endl;
}

string Employee::getDeptName() {
    return string("员工");
}

Employee::~Employee(){}