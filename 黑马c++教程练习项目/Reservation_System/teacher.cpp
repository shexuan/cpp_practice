//
// Created by shexuan on 2021/1/30.
//
#pragma once
#include "order_file.h"

#include <iostream>
#include <string>
using namespace std;
#include "teacher.h"

// 默认构造
Teacher::Teacher(){

}

// 有参构造
Teacher::Teacher(int id, string name, string pwd){
    this->m_id = id;
    this->m_name = name;
    this->m_pwd = pwd;
}


// 显示菜单栏
void Teacher::show_menu(){
    cout << "欢迎教师 " << this->m_name << " 登录！" << endl;
    cout << "====================================" << endl;
    cout << "           * 1. 查看所有预约  *             " << endl;
    cout << "           * 2. 审 核 预 约  *           " << endl;
    cout << "           * 0. 注 销 登 录  *            " << endl;
    cout << "====================================" << endl;
}

// 查看所有人的预约，这个与学生类的完全相同，可以直接调用学生类对象方法
void Teacher::show_orders(){
    OrderFile of;
    if(of.m_Size==0){
        cout << "无预约记录！" << endl;
        cin.get();
        system("clear");
        return;
    }
    int i=1;
    for (auto &m:of.m_orderData){
        cout << "\t" <<i << "、"
             << "\t预约日期：周" << m.second["date"]
             << "\t时间段：" << (m.second["interval"]=="1"?"上午":"下午")
             << "\t学号：" << m.second["stuID"]
             << "\t姓名：" << m.second["stuName"]
             << "\t机房编号：" << m.second["roomID"];
        string status = "状态：";
        if(m.second["status"]=="1"){
            status += "审核中";
        }else if(m.second["status"]=="2"){
            status += "预约成功";
        }else if(m.second["status"]=="-1"){
            status += "预约失败，审核未通过";
        }else{
            status += "预约已取消";
        }
        cout << "\t预约状态：" << status << endl;
        i++;
    }
    cin.get();
    system("clear");
}

// 审核预约, 跟学生取消预约实现思路是一样的
void Teacher::valid_order(){
    OrderFile of;
    if(of.m_Size==0){
        cout << "无预约记录！" << endl;
        cin.get();
        system("clear");
        return;
    }
    int i=0;
    map<int, int> mmap; // key为提取出的我的预约记录的index，value为预约记录文件中的我的预约记录的index
    int my_idx=1;
    for (auto &m:of.m_orderData){
        if(m.second["status"]=="1"){
            cout << "\t" <<my_idx << "、"
                 << "\t预约日期：周" << m.second["date"]
                 << "\t时间段：" << (m.second["interval"]=="1"?"上午":"下午")
                 << "\t学号：" << m.second["stuID"]
                 << "\t姓名：" << m.second["stuName"]
                 << "\t机房编号：" << m.second["roomID"];
            string status = "状态：";
            if(m.second["status"]=="1"){
                status += "审核中";
            }else if(m.second["status"]=="2"){
                status += "预约成功";
            }else if(m.second["status"]=="-1"){
                status += "预约失败，审核未通过";
            }else{
                status += "预约已取消";
            }
            cout << "\t预约状态：" << status << endl;
            // 记录我的预约idx与预约文件中idx的映射关系
            mmap.insert(pair<int, int>(my_idx, i));
            my_idx++;
        }
        i++;
    }

    if (mmap.size()==0){
        cout << "待审核预约数量为0" << endl;
        cin.get();
        system("clear");
        return;
    }

    int select;
    while (true){
        cout << "请输入您的选择：";
        cin >> select;
        if (select>my_idx || select <1){
            cout << "输入选项不在范围内，请重新选择！" << endl;
        }else{
            int select2 = 0;
            cout << "确认取消？(1-确定审核通过；others-取消确认)：";
            cin >> select2;
            if (select2==1){
                of.m_orderData[mmap[select]]["status"] = "2";
                cout << "审核成功！" << endl;
                of.update_order();
                break;
            }else{
                cout << "取消操作，返回" << endl;
                break;
            }
        }
    }

}

