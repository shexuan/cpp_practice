//
// Created by shexuan on 2021/1/30.
//
#pragma once
#include <string>
#include <iostream>
using namespace std;

#ifndef RESERVATION_SYSTEM_IDENTITY_H
#define RESERVATION_SYSTEM_IDENTITY_H

// 抽象身份基类
class Identity {
public:
    // 显示子菜单，纯虚函数，子类必须重写实现，否则子类也是抽象函数
    virtual void show_menu()=0;
    // 虚析构，用来调用析构子对象
    virtual ~Identity()=default;
    // 用户名
    string m_name;
    // 密码
    string m_pwd;
};


#endif //RESERVATION_SYSTEM_IDENTITY_H
