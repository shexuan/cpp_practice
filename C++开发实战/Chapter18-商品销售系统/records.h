//
// Created by shexuan on 2021/2/13.
//

#ifndef CHAPTER18__RECORDS_H
#define CHAPTER18__RECORDS_H
#pragma once

#include <string>
#include <utility>
#include <vector>

using namespace std;

/* 采购/销售记录包含的信息是一样的，因此可以采用同一个类。其包含的信息有：
 *  - 商品名称；
 *  - 交易日期；
 *  - 交易数量；
 */


// 也可以定义为struct，意思是一样的
class Record{
public:
    Record(string name, int num, string time){
        this->m_name = std::move(name);
        this->m_time = std::move(time);
        this->m_num = num;
    };

    friend ostream &operator<<(ostream &out, Record &rec){
        out << "\t商品名称: " << rec.m_name
            << "\t交易数量: " << rec.m_num
            << "\t交易时间: " << rec.m_time;
        return out;
    }

    // 这些属性按严格规定写法应该放入private中，然后通过get、set来进行获取值和赋值的。
    // 这里为了方便直接设为public
    string m_name;  // 商品名称
    string m_time;  // 交易时间
    int m_num;      // 交易数量
};

#endif //CHAPTER18__RECORDS_H
