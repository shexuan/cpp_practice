//
// Created by shexuan on 2021/2/11.
//
#pragma once

#include <fstream>
#include "bookManager.h"


bookManager::bookManager(){
    ifstream ifs;
    ifs.open(FILEPATH, ios::in);

    // 文件不存在
    if(ifs.fail()){
        cout << "文件不存在！" << endl;
        this->file_isEmepty = true;
        this->bk_num = 0;
        this->v_book.clear();
        return;
    }

    // 文件为空
    char c;
    ifs >> c;
    if(ifs.eof()){
        cout << "文件为空！" << endl;
        this->file_isEmepty = true;
        this->bk_num = 0;
        this->v_book.clear();
        ifs.close();
        return;
    }
    ifs.putback(c);

    // 文件存在且不为空，将图书信息读入
    this->file_isEmepty = false;
    this->v_book.clear();
    this->bk_num = 0;
    string name, isbn, author;
    float price;
    while(ifs >> name && ifs >> isbn &&  ifs >> price && ifs >> author){
        this->v_book.emplace_back(Book(name, isbn, price, author));
        this->bk_num ++;
    }
    ifs.close();

    cout << "当前图书馆共有 " << this->bk_num << " 册图书." << endl;
}

// 保存文件
void bookManager::save_file(){
    ofstream ofs;
    ofs.open(FILEPATH, ios::trunc);
    if(ofs.fail()){
        cout << "文件保存失败！" << endl;
        return;
    }

    for (auto &bk:this->v_book){
        ofs << bk.bk_name << " "
            << bk.bk_ISBN << " "
            << bk.bk_price << " "
            << bk.bk_author << endl;
    }

    ofs.close();
}

// 添加图书
bool bookManager::add_book(){
    string name, isbn, author;
    float price;
    cout << "请输入书名：";
    cin >> name;
    cout << "请输入书籍ISBN号：";
    cin >> isbn;
    cout << "请输入书籍价格：";
    cin >> price;
    cout << "作者：";
    cin >> author;

    this->v_book.emplace_back(Book(name, isbn, price, author));
    this->save_file();
}

// 显示所有图书
void bookManager::show_books(){
    for (auto &bk:this->v_book){
        cout << setw(20)<<"书名：" << bk.bk_name
                << setw(20)<< "ISBN号：" << bk.bk_ISBN
                << setw(20)<< "价格：" << bk.bk_price
                << setw(20)<< "作者：" << bk.bk_author << endl;
    }
}

// 搜索图书, 这里仅实现通过书名来检索书籍
bool bookManager::search_book(){
    cout << "请输入书籍名字：";
    string name;
    cin >> name;
    for (auto &bk:this->v_book){
        if(bk.bk_name==name){
            cout << "\t书名：" << bk.bk_name
                 << "\tISBN号：" << bk.bk_ISBN
                 << "\t价格：" << bk.bk_price
                 << "\t作者：" << bk.bk_author << endl;
        }
    }
}

// 删除书籍
void bookManager::delete_book(){
    cout << "请输入待删除书籍名字：";
    string name;
    cin >> name;
    vector<Book> vb;
    for (const auto& bk:this->v_book){
        if(bk.bk_name==name){
            cout << "\t书名：" << bk.bk_name
                 << "\tISBN号：" << bk.bk_ISBN
                 << "\t价格：" << bk.bk_price
                 << "\t作者：" << bk.bk_author << endl;
            cout << "确认删除(1-确认；0-取消)：";
            int select;
            cin >> select;
            if(select==0){
                cout << "已取消删除!" << endl;
                return;
            }else{
                cout << "已删除！" << endl;
            }
        }else{
            vb.push_back(bk);
        }
    }
    this->v_book = vb;
    this->bk_num = this->v_book.size();
    // 将删除后剩余的书籍保存到文件中
    save_file();


}
