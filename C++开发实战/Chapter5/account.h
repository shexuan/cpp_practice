//
// Created by shexuan on 2021/2/3.
//
#pragma once

#include <string>
#include <iostream>

using namespace std;

#ifndef CHAPTER5_ACCOUNT_H
#define CHAPTER5_ACCOUNT_H

// 客户账号类，这里每个账号的信息包括：卡号，密码，余额
// 用户通过输入卡号及密码登入
class Account {
public:
    // 默认构造函数
    Account()=default;
    // 有参构造函数
    Account(string card, string pwd, double balance);

    // 拷贝构造函数
    Account(const Account &acc);

    string get_pwd();

    double get_balance();

    // 取钱后需要更新余额
    void set_balance(double m);

    string get_card();

private:
    string m_card;
    string m_pwd;
    double m_balance;
};


#endif //CHAPTER5_ACCOUNT_H
