//
// Created by shexuan on 2021/2/3.
//
#pragma once
#include "atm.h"
#include <string>
#include <fstream>

// 默认构造函数
ATM::ATM(){
    // 读入账户数据库
    ifstream ifs;
    ifs.open(ACCOUNT_FILE, ios::in);
    // 文件不存在
    if (!ifs.is_open()){
        cout << "妖兽啦，被人删库了~~~" << endl;
        ifs.close();
        return;
    }

    // 文件为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "妖兽啦，数据库被清空啦~~~" << endl;
        ifs.close();
        return;
    }

    // 文件存在且不为空
    ifs.putback(ch); // 将上面读取的那个字符读回来
    string card, pwd;
    double balance;
    while(ifs>>card && ifs>>pwd && ifs>>balance){
        // this->v_acc.push_back(Account(card, pwd, balance));
        this->v_acc.emplace_back(Account(card, pwd, balance));
    }
    ifs.close();
}



// 登录验证密码
bool ATM::validate_login(){
    if (this->v_acc.empty()){
        cout << "银行跑路囖！！！" << endl;
        return false;
    }

    cout << "欢迎登录XX银行ATM！" << endl;
    cout << "请输入卡号: " << endl;
    string card;
    cin >> card;

    // 检查卡号是否存在
    bool card_exist = false;
    for(auto &acc:this->v_acc){
        if (acc.get_card()==card){
            card_exist = true;
            break;
        }
    }
    if (!card_exist){
        cout << "卡号不存在，退出！" << endl;
        return false;
    }

    int n=0;
    cout << "请输入密码: " << endl;
    string pwd;
    cin >> pwd;
    bool flag=false;
    while (n<5){
        for (auto &acc: this->v_acc){
            if(acc.get_card()==card && acc.get_pwd()==pwd){
                cout << "欢迎卡号 " << card << " 的用户！" << endl;
                this->m_acc = acc;
                cin.get();
                system("clear");
                return true;
            }
        }

        // 输入错误，重新输入
        cout << "输入错误，请重新输入密码: " << endl;
        cin >> pwd;
        n++; //仅有5次输入机会
    }

    cout << "您已连续输入错误超过5次，严打盗卡，请10分钟后重试！" << endl;
    return false;
}

void ATM::show_menu() {
    cout << "---------- 欢迎使用XX银行ATM机！----------" << endl;
    cout << "             * 1、取   款 *             " << endl;
    cout << "             * 2、显示余额 *             " << endl;
    cout << "             * 0、退   出 *             " << endl;
    cout << "---------------------------------------" << endl;
}

// 取款
void ATM::withdrawl(){
    cout << "请输入您的取款金额：" << endl;
    double money;
    cin >> money;
    // 余额不足的情况提早退出
    if (money>this->m_acc.get_balance()){
        cout << "余额不足！" << endl;
        cin.get();
        system("clear");
        return;
    }
    // 余额足够
    double res = this->m_acc.get_balance()-money;
    this->m_acc.set_balance(res);
    cout << "您已取出 " << money << " 元，卡中余额 " << this->m_acc.get_balance() << "元." << endl;

    // 更新文件
    ofstream ofs;
    ofs.open(ACCOUNT_FILE, ios::out|ios::trunc);
    for (vector<Account>::iterator it=this->v_acc.begin(); it!=this->v_acc.end();it++){
        if(it->get_card()==this->m_acc.get_card()){
            it->set_balance(res);
        }
        ofs << it->get_card() << " "
            << it->get_pwd() << " "
            << it->get_balance() << endl;
    }
    ofs.close();
}

// 显示余额
void ATM::show_balance(){
    cout << "您的账户余额为：" << this->m_acc.get_balance() <<" 元." <<endl;
    cin.get();
    system("clear");
}