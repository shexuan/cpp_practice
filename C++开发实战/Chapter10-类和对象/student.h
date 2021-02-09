//
// Created by shexuan on 2021/2/8.
//

#ifndef CHAPTER10__STUDENT_H
#define CHAPTER10__STUDENT_H
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    // 有参初始化
    Student(int id, string name, int score);

    friend bool my_greater(const Student &stu1, const Student &stu2);
//    {
//        return stu1.m_score > stu2.m_score;
//    }

    bool operator>(const Student &stu);

    friend ostream &operator<<(ostream & cout, const Student &stu);

private:
    int m_id;
    string m_name;
    int m_score;
};


#endif //CHAPTER10__STUDENT_H
