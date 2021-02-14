//
// Created by shexuan on 2021/2/13.
//

#pragma once

#include <string>
#include <vector>
#include "salesManager.h"
#include <iostream>
#include <algorithm>

using namespace std;


// 初始化，包括读入商品信息文件，销售记录文件，购入记录文件
salesManager::salesManager(){
    // 初始化商品列表
    ifstream ifs(COMMODITYFILE, ios::in);
    if(ifs.fail()){  // 商品文件打开失败
        cout << "商品文件打开失败!" << endl;
    } else{ // 文件打开成功
        this->m_vComm.clear();
        char ch;
        ifs >> ch;  // 拿出一个字符出来
        if(ifs.eof()){
            cout << "商品文件为空！" << endl;
            ifs.close();
        }else{ // 文件不为空
            ifs.putback(ch);
            int id=0; // 商品编号
            int stock=0; // 库存数量
            float buyPrice=0.f;   // 进价
            float sellPrice=0.f;  // 售价
            string name;
            while (ifs>>id && ifs>>name && ifs>>buyPrice && ifs>>sellPrice && ifs>>stock){
                this->m_vComm.emplace_back(Commodity(id, name, stock, buyPrice, sellPrice));
            }
            ifs.close();
        }
    }

    // 初始化采购记录列表
    ifstream ifs1(BUYRECOREDFILE, ios::in);
    if(ifs1.fail()){  // 商品文件打开失败
        cout << "采购记录文件打开失败!" << endl;
    } else{ // 文件打开成功
        this->m_buyRec.clear();
        char ch;
        ifs1 >> ch;  // 拿出一个字符出来
        if(ifs1.eof()){
            cout << "商品文件为空！" << endl;
            ifs1.close();
        }else{ // 文件不为空
            ifs1.putback(ch);
            string name;  // 商品名称
            string ttime;  // 交易时间
            int num=0;      // 交易数量
            while (ifs1>>name && ifs1>>num && ifs1>>ttime){
                this->m_buyRec.emplace_back(Record(name, num, ttime));
            }
            ifs1.close();
        }
    }

    // 初始化采购记录列表
    ifstream ifs2(SALERECORDFILE, ios::in);
    if(ifs2.fail()){  // 商品文件打开失败
        cout << "销售记录文件打开失败!" << endl;
    } else{ // 文件打开成功
        this->m_saleRec.clear();
        char ch;
        ifs2 >> ch;  // 拿出一个字符出来
        if(ifs2.eof()){
            cout << "销售记录文件为空！" << endl;
            ifs2.close();
        }else{ // 文件不为空
            ifs2.putback(ch);
            string name;  // 商品名称
            string ttime;  // 交易时间
            int num=0;      // 交易数量
            while (ifs2>>name && ifs2>>num && ifs2>>ttime){
                this->m_saleRec.emplace_back(Record(name, num, ttime));
            }
            ifs2.close();
        }
    }

}

// 显示所有商品信息
void salesManager::show_commodity(){
    cout << "店铺当前出售商品如下: " << endl;
    for_each(this->m_vComm.begin(), this->m_vComm.end(),
            [](Commodity &c){ cout << c << endl;});
    cin.get();
    system("clear");
}

int salesManager::comm_isExist(const string& name) {
    for(int i=0; i<this->m_vComm.size(); i++){
        if(this->m_vComm[i].m_name==name){
            return i;
        }
    }
    return -1;
}

string salesManager::get_time(){
    time_t t;  //秒时间
    tm* local; //本地时间
    char buf[128]= {0};

    t = time(NULL); //获取目前秒时间
    local = localtime(&t); //转为本地时间
    string s;
    strftime(buf, 64, "%Y-%m-%d", local);
    s = buf;
    return s;
}

// 更新采购记录
void salesManager::update_buyRecords(){
    ofstream ofs(BUYRECOREDFILE, ios::trunc);
    if(ofs.fail()){
        cout << "打开采购记录文件失败！" << endl;
    }else{
        for(auto &r:this->m_buyRec){
            ofs << r.m_name << " "
                << r.m_num << " "
                << r.m_time << endl;
        }
        ofs.close();
    }
}

// 更新销售记录
void salesManager::update_sellRecords(){
    ofstream ofs(SALERECORDFILE, ios::trunc);
    if(ofs.fail()){
        cout << "打开销售记录文件失败！" << endl;
    }else{
        for(auto &r:this->m_saleRec){
            ofs << r.m_name << " "
                << r.m_num << " "
                << r.m_time << endl;
        }
        ofs.close();
    }
}

void salesManager::update_commodity(){
    ofstream ofs(COMMODITYFILE, ios::trunc);
    for(auto &c:this->m_vComm){
        ofs << c.m_id << " "
            << c.m_name << " "
            << c.m_buyPrice << " "
            << c.m_sellPrice << " "
            << c.m_stock << endl;
    }
    ofs.close();
}

void salesManager::find_commodity() {
    cout << "请输入您要查询的商品名称：";
    string name;
    cin >> name;
    int index = comm_isExist(name);
    if (index == -1) {
        cout << "您查询的商品不存在，您也可以看看其他商品！" << endl;
        return;
    } else {
        cout << "您查询的商品信息如下：" << endl;
        cout << this->m_vComm[index] << endl;
    }
    cin.get();
    system("clear");
}

// 售出商品
void salesManager::sales_commodity(){
    cout << "请输入您要购买的商品名称：";
    string name;
    cin >> name;
    int index = comm_isExist(name);
    if(index==-1){
        cout << "您购买的商品不存在，您也可以看看其他商品！" << endl;
        return;
    }else{
        cout << "您要购买的商品信息如下：" << endl;
        cout << this->m_vComm[index] << endl;
        cout << endl;
        int num;
        do{
            cout << "请输入您要购买的数量(剩余可购买数量为" << this->m_vComm[index].m_stock << "，输入0返回上一层)：";
            cin >> num;
            if(num==0){
                cin.get();
                system("clear");
                return;
            }
        }while(num > this->m_vComm[index].m_stock);
        // 购买成功后需要将库存减少
        this->m_vComm[index].m_stock = this->m_vComm[index].m_stock - num;
        // 若商品库存为0，将从现有商品中删除
        if(this->m_vComm[index].m_stock==0){
            this->m_vComm.erase(this->m_vComm.begin()+index);
        }
        // 商品变动写入文件中
        update_commodity();
        cout << "购买成功！" << endl;

        // 更新购买记录
        string ts = get_time();
        this->m_saleRec.emplace_back(Record(name, num, ts));
        update_sellRecords();

        cin.get();
        system("clear");
    }
}

// 采购商品
void salesManager::buy_commodity(){
    cout << "请输入采购商品名称：";
    string name;
    cin >> name;
    int index = comm_isExist(name);
    int num;
    cout << "请输入您要采购的数量(输入0返回上一层)：";
    cin >> num;
    if(num==0){
        cin.get();
        system("clear");
        return;
    }

    if(index==-1){  // 采购新商品，添加到商品列表中
        float buyPrice;
        float sellPrice;
        int id;
        cout << "请输入采购商品编号：";
        cin >> id;
        cout << "请输入商品采购单价：";
        cin >> buyPrice;
        cout << "请输入商品出售单价：";
        cin >> sellPrice;
        this->m_vComm.emplace_back(Commodity(id, name, num, buyPrice, sellPrice));
    }else{  // 店铺中已有采购商品———增加采购商品库存
        this->m_vComm[index].m_stock += num;
    }
    // 写入文件中
    update_commodity();
    cout << "采购成功！" << endl;

    // 更新采购记录
    string ts = get_time();
    this->m_buyRec.emplace_back(Record(name, num, ts));
    update_buyRecords();

    cin.get();
    system("clear");
}

// 显示采购记录
void salesManager::show_buyRecords(){
    for_each(this->m_buyRec.begin(), this->m_buyRec.end(),
            [](Record &r){cout << r << endl;});
}

// 显示销售记录
void salesManager::show_saleRecords(){
    for_each(this->m_saleRec.begin(), this->m_saleRec.end(),
             [](Record &r){cout << r << endl;});
}
