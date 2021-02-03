//
// Created by shexuan on 2021/2/3.
//
#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "account.h"
#include "globalFile.h"
#include <map>
#include <vector>

#ifndef CHAPTER5_ATM_H
#define CHAPTER5_ATM_H


class ATM {
public:
    // 默认构造函数
    ATM();

    // 登录验证密码
    bool validate_login();

    // 验证通过后显示目录
    void show_menu();

    // 取款
    void withdrawl();

    // 显示余额
    void show_balance();

    // 记录账户
    vector<Account> v_acc;

    // 当前登录用户
    Account m_acc;

};


#endif //CHAPTER5_ATM_H
