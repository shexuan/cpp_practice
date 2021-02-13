//
// Created by shexuan on 2021/2/13.
//

#ifndef CHAPTER16_STL_GOODS_H
#define CHAPTER16_STL_GOODS_H
#pragma once
#include <string>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

class Good{
public:
    Good(){};
    Good(int id, float price, int num){
        m_id = id;
        m_price = price;
        m_num = num;
    }

    // 重载比较运算符，排序时候用到
    friend bool gless(Good &g1, Good &g2);
//    {
//        return g1.m_id < g2.m_id;
//    }


    friend ostream &  operator<<(ostream &cout, Good &g){
        cout << "\t商品编号: " << g.m_id
            << "\t价格: " << g.m_price
            << "\t库存: " << g.m_num;
        return cout;
    }

    int m_id;  // 商品编号
    float m_price;  // 商品价格
    int m_num;  // 库存数量
};


// 使用仿函数来定义谓词
class mySort{
public:
    explicit mySort(string select){
        m_select = std::move(select);
    }

    bool operator()(const Good &g1, const Good &g2){
        if(m_select=="id"){
            return g1.m_id<g2.m_id;
        } else if(m_select=="price"){
            return g1.m_price<g2.m_price;
        } else if(m_select=="num"){
            return g1.m_num==g2.m_num;
        }
    }
    string m_select;  // 按那个商品属性来进行排序
};
#endif //CHAPTER16_STL_GOODS_H
