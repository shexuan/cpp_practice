//
// Created by shexuan on 2021/2/11.
//

#ifndef CHAPTER14__BOOKMANAGER_H
#define CHAPTER14__BOOKMANAGER_H
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "book.h"

#define FILEPATH "/Users/shexuan/cpp_practice/C++开发实战/Chapter14-图书馆管理系统/book.txt"


/* 图书馆管理类需要实现一下需求：

    *  （1）图书录入模块：实现交互式录入图书；
    *  （2）浏览全部图书模块：用户能够浏览文件中储存的全部图书，图书信息显示格式要一致；
    *  （3）删除图书模块：以售完的书需要删除；
    *  （4）图书检索模块：用户根据作者或者书名来检索图书；
*/
class bookManager {
public:
    // 初始化，需要实现从数据库文件中读入所有图书资料
    bookManager();

    // 添加图书
    bool add_book();

    // 显示所有图书
    void show_books();

    // 搜索图书, 这里仅实现通过书名来检索书籍
    bool search_book();

    // 删除书籍
    void delete_book();

private:
    // 每次添加或删除书籍后都要重新将当前书籍信息写入文件中
    void save_file();

    vector<Book> v_book;
    bool file_isEmepty;  // 图书馆记录文件是否存在
    int bk_num;  // 当前有多少图书


};


#endif //CHAPTER14__BOOKMANAGER_H
