//
// Created by shexuan on 2021/2/11.
//

#ifndef CHAPTER14__BOOK_H
#define CHAPTER14__BOOK_H
#pragma once

#include <string>
#include <iostream>
using namespace std;


/* Book类也可用struct来实现
 * 包含的属性有：
 *  - 书名；
 *  - ISBN号；
 *  - 价格；
 *  - 作者；
 */

class Book {
public:  // 这里为了方便直接全部设置成public
    // 提供一种无参初始化方式
    Book(){};

    // 有参初始化方式
    Book(string name, string isbn, float price, string author){
        this->bk_name = name;
        this->bk_ISBN = isbn;
        this->bk_price = price;
        this->bk_author = author;
    }

    string bk_name;
    string bk_ISBN;
    float bk_price;
    string bk_author;
};


#endif //CHAPTER14__BOOK_H
