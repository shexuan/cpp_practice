//
// Created by shexuan on 2021/1/31.
//

#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "globalFile.h"

using namespace std;

#ifndef RESERVATION_SYSTEM_ORDER_H
#define RESERVATION_SYSTEM_ORDER_H


class OrderFile {
public:
    // 构造函数
    OrderFile();

    // 更新预约记录
    void update_order();

    // 记录预约条数
    int m_Size;

    // 记录所有预约信息的容器，key记录条数，value记录具体键值对信息
    map<int, map<string, string>> m_orderData;
};


#endif //RESERVATION_SYSTEM_ORDER_H
