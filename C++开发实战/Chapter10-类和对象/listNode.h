//
// Created by shexuan on 2021/2/8.
//

#ifndef CHAPTER10__LISTNODE_H
#define CHAPTER10__LISTNODE_H

#pragma once
#include <iostream>
#include <string>

using namespace std;

class ListNode {
public:
    // 有参构造函数
    ListNode(int data);

    // 向尾部添加结点
    static void add_node(ListNode * node);

    // 向尾部添加结点
    static void add_node(int data);

    // 根据内容删除结点
    static bool del_node(int data);

    // 显示所有结点
    static void show_node();

    int m_data;
    ListNode *next;
    static ListNode * pHead;
    static ListNode * pTail;
};


#endif //CHAPTER10__LISTNODE_H
