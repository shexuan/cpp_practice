//
// Created by shexuan on 2021/2/10.
//

#ifndef CHAPTER11__LISTNODE_H
#define CHAPTER11__LISTNODE_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

typedef class StudentLink{
    typedef struct StudentNode{
        char name[20];
        float score;
        StudentNode *Next;
        StudentNode(char* name, float score){
            strcpy(this->name, name);
            this->score = score;
            this->Next = NULL;
        }
    }SN;

private:
    SN *pHead; // 链表头
    SN *pTail; // 链表尾

public:
    StudentLink(){
        pHead = NULL;
        pTail = NULL;
    }

    // 增加结点
    void AddNode(char * name, float score){
        SN *pNode = new SN(name, score);
        if (pHead==NULL){
            pHead = pNode;
            pTail = pHead;
            return;
        }

        pTail->Next = pNode;
        pTail = pNode; // pTail = pTail->Next;
    }

    // 加入链表的后方，合并出新链表
    StudentLink Join(StudentLink link){
        if(link.pHead==NULL){
            link.pHead = pHead;
        }
        link.pTail->Next = pHead;  // 这里将当前加入别的link的尾部了
        link.pTail = pTail;  // 此时link为新链表指针
        return link;
    }

    void GetMessage(){
        if(pHead==NULL){
            cout << "链表是空的！" << endl;
            return;
        }
        StudentNode* pMove = pHead;
        cout << endl;
        while(pMove!=NULL){
            cout << "\t姓名: " << pMove->name
                << "\t成绩: " << pMove->score << endl;
            pMove = pMove->Next;
        }
    }

}SL;




#endif //CHAPTER11__LISTNODE_H
