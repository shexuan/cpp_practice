//
// Created by shexuan on 2021/2/8.
//
#pragma once
#include "student.h"

Student::Student(int id, string name, int score){
    this->m_id = id;
    this->m_name = name;
    this->m_score = score;
}

//bool my_greater(const Student &stu1, const Student &stu2){
//    return stu1.m_score > stu2.m_score;
//}

bool Student::operator>(const Student &stu){
    return this->m_score > stu.m_score;
}

ostream & operator<<(ostream & cout, const Student &stu){
    cout << "学号：" << stu.m_id << "\t姓名：" << stu.m_name << "\t分数：" << stu.m_score << endl;
    return cout;
}