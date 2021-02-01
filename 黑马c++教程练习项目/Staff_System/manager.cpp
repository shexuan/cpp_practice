//
// Created by shexuan on 2021/1/12.
//

#pragma onece
#include <iostream>
#include <string>
#include "manager.h"

using namespace std;

Manager::Manager(int id, string name, int dept_id){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dept_id;
}


void Manager::show_info() {
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t职工岗位：" << this->getDeptName()
         << "\t岗位职责：完成老板交给的任务，并下发任务给普通员工"
         << endl;
}

string Manager::getDeptName() {
    return string("经理");
}

Manager:: ~Manager(){}