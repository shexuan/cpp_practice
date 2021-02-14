//
// Created by shexuan on 2021/2/13.
//

#ifndef CHAPTER18__COMMODITY_H
#define CHAPTER18__COMMODITY_H
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Commodity{
public:
    Commodity()= default;;

    Commodity(int id, string name, int stock, float buyPrice, float sellPrice){
        this->m_id = id;
        this->m_name = name;
        this->m_buyPrice = buyPrice;
        this->m_sellPrice = sellPrice;
        this->m_stock = stock;
    }
    
    // 这里其实不需要设置为友元函数也可以
    friend ostream &operator<<(ostream &out, Commodity &c){
         out << "\t商品编号: " << c.m_id
            << "\t名称: " << c.m_name
            << "\t采购价格: " << c.m_buyPrice
            << "\t出售价格: " << c.m_sellPrice
            << "\t库存: " << c.m_stock;
        return out;
    }

    int m_id; // 商品编号
    int m_stock; // 库存数量
    float m_buyPrice;   // 进价
    float m_sellPrice;  // 售价
    string m_name;

};

#endif //CHAPTER18__COMMODITY_H
