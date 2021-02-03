//
// Created by shexuan on 2021/2/3.
//

#include "account.h"

// 有参构造函数
Account::Account(string card, string pwd, double balance){
    this->m_pwd = pwd;
    this->m_balance = balance;
    this->m_card = card;
}

// 拷贝构造函数
Account::Account(const Account &acc){
    this->m_card = acc.m_card;
    this->m_balance = acc.m_balance;
    this->m_pwd = acc.m_pwd;
}

string Account::get_pwd(){
    return this->m_pwd;
}

double Account::get_balance(){
    return this->m_balance;
}

void Account::set_balance(double m) {
    this->m_balance = m;
}

string Account::get_card(){
    return this->m_card;
}