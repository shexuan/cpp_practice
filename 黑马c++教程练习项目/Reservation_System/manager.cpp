//
// Created by shexuan on 2021/1/30.
//
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "manager.h"
#include "globalFile.h"
#include <algorithm>

using namespace std;

// 默认构造函数
Manager::Manager(){}


// 有参构造函数
Manager::Manager(string name, string pwd){
    this->m_name = name;
    this->m_pwd = pwd;

    this->init_vector();

    // 初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
    }else{
        computerRoom comp;
        while(ifs>>comp.m_roomId && ifs>>comp.m_maxNum){
            this->v_computer.push_back(comp);
        }
        ifs.close();
    }
}


// 显示管理员菜单
void Manager::show_menu(){
    cout << "欢迎管理员 " << this->m_name << " 登录！" << endl;
    cout << "====================================" << endl;
    cout << "           * 1. 添加账号  *             " << endl;
    cout << "           * 2. 查看账号  *           " << endl;
    cout << "           * 3. 查看机房  *           " << endl;
    cout << "           * 4. 清空预约  *            " << endl;
    cout << "           * 0. 退出登录  *            " << endl;
    cout << "====================================" << endl;
}

void Manager::init_vector(){
    // 打开学生文件
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()){
        cout << "文件不存在！" << endl;
        return;
    }

    this->v_stu.clear();
    this->v_tea.clear();
    // 读取学生信息
    Student s;
    while(ifs>>s.m_id && ifs>>s.m_name && ifs>>s.m_pwd){
        v_stu.push_back(s);
    }
    cout << "当前学生数量为：" << v_stu.size() << endl;
    ifs.close();

    // 读取老师信息
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
    }
    Teacher t;
    while (ifs>>t.m_id && ifs>>t.m_name && ifs>>t.m_pwd){
        v_tea.push_back(t);
    }
    cout << "当前教师的数量为：" <<v_tea.size() << endl;
    ifs.close();
}

bool Manager::is_repeat(int id, int type) {
    if (type==1){ // 学生
        for (int i=0;i<this->v_stu.size();i++){
            if(id==v_stu[i].m_id){
                return true;
            }
        }
        return false;
    }else if(type==2){  // 教师
        for (Teacher & t:v_tea){
            if(t.m_id==id){
                return true;
            }
        }
        return false;
    }else{ // 其他输入有错
        cout << "输入类型有误！" << endl;
        return true;
    }
}

// 添加用户
void Manager::add_user(){
    cout << "请输入添加账号的类型(1-学生，2-教师)：";
    int select;
    cin >> select;
    if (cin.fail()){ // 输入的不是数字
        cout << "输入选项错误，返回上一层！" << endl;
        return;
    }

    int id=0;
    string name;
    string pwd;
    string filename;
    if (select==1){ // 添加学生
        filename = STUDENT_FILE;
        cout << "请输入学号：" ;
        cin >> id;
        if (cin.fail()){ // 输入的不是数字
            cout << "输入选项错误，返回上一层！" << endl;
            return;
        }
        // 检查输入的学号是否重复

    } else if(select==2){ // 添加教师
        filename = TEACHER_FILE;
        cout << "请输入教师职工号：";
        cin >> id;
        if (cin.fail()){ // 输入的不是数字
            cout << "输入选项错误，返回上一层！" << endl;
            return;
        }
    }else{
        cout << "输入选项错误，返回" <<endl;
        return;
    }
    // 检查id是否有重复
    while (true){
        bool ret = this->is_repeat(id, select);
        if (ret){ // 有重复
            cout << "ID重复，请重新输入ID：" << endl;
            cin >> id;
        }else{
            break;
        }
    }

    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;

    // 打开文件，先比较是否有id重复，无重复则写入文件
    ofstream ofs;
    ofs.open(filename, ios::app);
    if(!ofs.is_open()){
        cout << "文件打开失败！" << endl;
        return;
    }

    // 写入数据
    ofs << endl; // 这一步可能是由于不同的系统不同文件类型(如ascii编码文件)，不加的话会添加到上一行尾
    ofs << id << " " << name << " " << pwd << endl;
    ofs.close();
    cout << "创建账号成功！" << endl;

    // 重新初始化容器，读取新增的账号
    this->init_vector();
}


void print_teacher(const Teacher & t){
    cout << "职工号：" << t.m_id
         << "姓名：" << t.m_name
         << "密码：" << t.m_pwd << endl;
}

// 查看账号
void Manager::show_account(){
    int select;
    cout << "请选择查看的账号类型(1-学生；2-教师)：";
    cin >> select;
    if (select==1){
        for (auto &p:this->v_stu){
            cout << "学号：" << p.m_id
                << "姓名：" << p.m_name
                << "密码：" << p.m_pwd << endl;
        }
    }else if(select==2){
        for_each(this->v_tea.begin(), this->v_tea.end(), print_teacher);
    }

}

// 查看机房信息
void Manager::show_compRoom(){
    cout << "机房信息如下：" << endl;
    for (auto c=v_computer.begin();c!=v_computer.end(); c++){
        cout << "\t机房编号：" << c->m_roomId
            << "\t机房机子数量：" << c->m_maxNum << endl;
    }
}

// 清空预约信息
void Manager::clear_orders(){
    cout << "确认情况预约？(1-确认；2-取消) ";
    int select;
    cin >> select;
    if (select!=1){
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "已清空预约！" << endl;
    cin.get();
    system("clear");
}

Manager::~Manager(){
    cout << "虚析构" << endl;
}