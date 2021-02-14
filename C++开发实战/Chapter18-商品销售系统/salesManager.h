//
// Created by shexuan on 2021/2/13.
//

#ifndef CHAPTER18__SALESMANAGER_H
#define CHAPTER18__SALESMANAGER_H

#pragma once
#include "commodity.h"
#include "records.h"
#include "globalFile.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* 商品销售系统包括如下功能：
 *  （1）显示所有商品；
 *  （2）购入商品；
 *  （3）售出商品；
 *  （4）显示购入记录；
 *  （5）显示销售记录；
 */

class salesManager {
public:
    // 初始化，包括读入商品信息文件，销售记录文件，购入记录文件
    salesManager();

    // 显示所有商品信息
    void show_commodity();

    // 购入商品
    void buy_commodity();

    // 出售商品
    void sales_commodity();

    // 显示采购记录
    void show_buyRecords();

    // 显示销售记录
    void show_saleRecords();

    // 查询商品
    void find_commodity();

private:
    // 查找商品是否存在
    int comm_isExist(const string& name);

    // 更新商品信息
    void update_commodity();

    // 获取当前时间
    string get_time();

    // 更新采购记录
    void update_buyRecords();

    // 更新销售记录
    void update_sellRecords();

public:
    int kinds;  // 商品数量
    vector<Commodity> m_vComm;
    vector<Record> m_buyRec;
    vector<Record> m_saleRec;
};


#endif //CHAPTER18__SALESMANAGER_H

