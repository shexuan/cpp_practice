//
// Created by shexuan on 2021/2/8.
//

#include "listNode.h"

ListNode::ListNode(int data) {
    this->m_data = data;
    this->next = nullptr;
}

// 向尾部添加结点，这里提供结点数据
void ListNode::add_node(int data) {
    if(pHead==nullptr){
        pHead = new ListNode(data);
        pTail = pHead;
        return;
    }else{
        pTail->next = new ListNode(data);
        pTail = pTail->next;
        return;
    }
}

void ListNode::add_node(ListNode * node) {
    if(pHead==nullptr){
        pHead = node;
        pTail = pHead;
        return;
    }else{
        pTail->next = node;
        pTail = pTail->next;
        return;
    }
}

bool ListNode::del_node(int data){
    bool flag = false;
    if(pHead==nullptr){
        return flag;
    }

    // 遍历查找符合条件的点
    ListNode * pTemp = pHead;
    if(pHead->m_data==data){
        pTemp = pHead->next;
        delete pHead;
        pHead = pTemp;
//        if(pHead==NULL){
//            return true;
//        }
        return true;
    }
    // 头结点不是要删的点，继续查找
    ListNode * pMove = pHead->next;
    while(pMove!=NULL){
        if(pMove->m_data==data){
            pTemp->next = pMove->next;
            delete pMove;
            pMove = pTemp->next; // 结点迭代指针回到链表
            return true;
        }else{ // 移动指针
            pMove = pMove->next;
            pTemp = pTemp->next;  // pTemp始终是pMove的上一个结点
        }
    }
    return flag;
}


void ListNode::show_node() {
    if(pHead==NULL){
        cout << "当前链表为空" << endl;
    }else{
        ListNode * pMove = pHead;
        while(pMove!=NULL){
            cout << pMove->m_data << " ";
            pMove = pMove->next;
        }
        cout << endl;
    }
}


//ListNode * ListNode::pHead = NULL;
//ListNode * ListNode::pTail = NULL;
