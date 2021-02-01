//
// Created by shexuan on 2021/1/30.
//
#pragma once

#include <iostream>
#include <string>
#include "student.h"
#include <fstream>
#include "order_file.h"

/*
*  学生具体功能：
*      - 申请预约：预约机房；
*      - 查看自身的预约：查看自己的预约状态；
*      - 查看所有的预约：查看全部预约信息及预约状态；
*      - 取消预约：取消自身的预约（预约成功或审核中的预约均可取消）；
*      - 注销登录：退出登录；
*/

// 默认构造
Student::Student(){

};

// 有参构造
Student::Student(int id, string name, string pwd){
    this->m_id = id;
    this->m_name = name;
    this->m_pwd = pwd;

    // 初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "机房文件不存在！" << endl;
    }else{
        computerRoom comp;
        while (ifs>>comp.m_roomId && ifs>>comp.m_maxNum){
            this->v_comp.push_back(comp);
        }
        ifs.close();
    }
}

// 显示学生菜单
void Student::show_menu(){
    cout << "欢迎学员 " << this->m_name << " 登录！" << endl;
    cout << "====================================" << endl;
    cout << "           * 1. 申 请 预 约  *             " << endl;
    cout << "           * 2. 查看我的预约  *           " << endl;
    cout << "           * 3. 查看所有预约  *           " << endl;
    cout << "           * 4. 取 消 预 约  *            " << endl;
    cout << "           * 0. 注 销 登 录  *            " << endl;
    cout << "====================================" << endl;
}

// 申请预约
void Student::apply_order(){
    cout << "请输入预约时间（仅周一至周五开放）：";
    cout << "1——周一" << endl;
    cout << "2——周二" << endl;
    cout << "3——周三" << endl;
    cout << "4——周四" << endl;
    cout << "5——周五" << endl;

    int date = 0;  // 日期
    int interval = 0;  // 时间段
    int room = 0;  // 机房编号

    while (true){
        cin >> date;
        if(date>=1 && date<=5){
            break;
        }
        else{
            cout << "日期输入有误，请重新输入！" << endl;
        }
    }

    cout << "请输入申请预约时间段(1-上午；2-下午)：" << endl;
    while (true){
        cin >> interval;
        if(interval==1 || interval==2){
            break;
        }else{
            cout << "时间段输入有误，请重新输入！" << endl;
        }
    }

    cout << "请选择机房：" << endl;
    for (auto &comp:v_comp){
        cout << "\t" <<comp.m_roomId << "号机房的容量为：" << comp.m_maxNum << endl;
    }
    bool valid_room=false;
    while (true){
        cin >> room;
        for (auto &comp:v_comp){
            if (room==comp.m_roomId){
                valid_room = true; // 找到room，合法输入
            }
        }
        if (valid_room){
            break;
        }else{
            cout << "您输入的机房不存在，请重新输入：";
        }
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);

    // 预约文件中录入信息
    ofs << "date:" << date << " "
        << "interval:" << interval << " "
        << "stuID:" << this->m_id <<  " "
        << "stuName:" << this->m_name << " "
        << "roomID:" << room << " "
        << "status:" << 1 << endl; // 1 表示审核中

    ofs.close();
    cin.get();
    system("clear");
}

// 查看自己的预约
void Student::show_myOrder(){
    OrderFile of;
    if(of.m_Size==0){
        cout << "无预约记录！" << endl;
        cin.get();
        system("clear");
        return;
    }
    for (auto &m:of.m_orderData){
        if (atoi(m.second["stuID"].c_str())==this->m_id){
            cout << "\t预约日期：周" << m.second["date"]
                << "\t时间段：" << (m.second["interval"]=="1"?"上午":"下午")
                // << "学号：" << m.second["stuID"]
                // << "姓名：" << m.second["stuName"]
                << "\t机房编号：" << m.second["roomID"];
            string status = "\t预约状态：";
            if(m.second["status"]=="1"){
                status += "审核中";
            }else if(m.second["status"]=="2"){
                status += "预约成功";
            }else if(m.second["status"]=="-1"){
                status += "预约失败，审核未通过";
            }else{
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
    cin.get();
    system("clear");
}

// 查看所有人的预约
void Student::show_allOrder(){
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


// 取消预约
void Student::cancel_order(){
    OrderFile of;
    if(of.m_Size==0){
        cout << "无预约记录！" << endl;
        cin.get();
        system("clear");
        return;
    }

    map<int, int> m; // key为提取出的我的预约记录的index，value为预约记录文件中的我的预约记录的index
    int my_idx=1;
    for (int i=0;i<of.m_orderData.size();i++) {
        if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_id) {
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
                // 将自身的预约输出以便选择取消那条预约
                cout << "\t" << my_idx << "、"
                     << "\t预约日期：周" << of.m_orderData[i]["date"]
                     << "\t时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
                     << "\t学号：" << of.m_orderData[i]["stuID"]
                     << "\t姓名：" << of.m_orderData[i]["stuName"]
                     << "\t机房编号：" << of.m_orderData[i]["roomID"];
                string status = "状态：";
                if (of.m_orderData[i]["status"] == "1") {
                    status += "审核中";
                } else if (of.m_orderData[i]["status"] == "2") {
                    status += "预约成功";
                } else if (of.m_orderData[i]["status"] == "-1") {
                    status += "预约失败，审核未通过";
                } else {
                    status += "预约已取消";
                }
                cout << "\t预约状态：" << status << endl;
                // 记录我的预约idx与预约文件中idx的映射关系
                m.insert(pair<int, int>(my_idx, i));
                my_idx++;
            }
        }
    }

    if (m.size()==0){
        cout << "当前预约成功/审核中记录数量为0" << endl;
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
            cout << "确认取消？(1-确定；others-取消确认)：";
            cin >> select2;
            if (select2==1){
                of.m_orderData[m[select]]["status"] = "0";
                cout << "取消预约成功！" << endl;
                of.update_order();
                break;
            }else{
                cout << "取消操作，返回" << endl;
                break;
            }
        }
    }

    cin.get();
    system("clear");
}

