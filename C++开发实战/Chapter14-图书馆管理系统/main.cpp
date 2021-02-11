#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "bookManager.h"

using namespace std;

/* 图书管管理系统
 *
 * 需求分析：
 * 明日书城是一家书店，为方便消费者对图书的检索，特开发此系统。此系统应符合以下要求：
 *  （1）可以真正的实现对图书信息的管理；
 *  （2）系统的功能操作要方便、易懂，不要有多余或复杂的操作；
 *  （3）信息输出格式便于浏览；
 *
 * 需求功能抽象化，将需求抽象为程序需要实现的功能：
 *  （1）图书录入模块：实现交互式录入图书；
 *  （2）浏览全部图书模块：用户能够浏览文件中储存的全部图书，图书信息显示格式要一致；
 *  （3）删除图书模块：以售完的书需要删除；
 *  （4）图书检索模块：用户根据作者或者书名来检索图书；
 */


void show_menu(){
    cout << endl;
    cout << std::setw(20) << " 1、添 加 图 书" << endl;
    cout << std::setw(20) << " 2、显示全部图书" << endl;
    cout << std::setw(20) << " 3、检 索 图 书" << endl;
    cout << std::setw(20) << " 4、删 除 图 书" << endl;
    cout << std::setw(20) << " 0、退 出 程 序" << endl;

    cout << endl;
}


int main() {
    cout << "欢迎光临 明日书城 ！" << endl;
    bookManager bm;
    while (true){
        show_menu();
        cout << "请选择操作：";
        int select;
        cin >> select;
        switch (select){
            case 1: // 显示图书
                bm.add_book();
                break;
            case 2:
                bm.show_books();
                break;
            case 3:
                bm.search_book();
                break;
            case 4:
                bm.delete_book();
                break;
            default:
                return 0;
                break;
        }

    }
    return 0;
}