//
// Created by shexuan on 2021/2/9.
//

#ifndef CHAPTER10__STUDENTNODE_H
#define CHAPTER10__STUDENTNODE_H
#pragma once

#include <iostream>
#include <string>
using namespace std;

typedef class StudentNode{
private:
    // 学生编号，姓名，年龄，成绩
    int id;
    char name[20];
    int age;
    float score;
    static int ID_buffer; // 自增的学生编号
    StudentNode *next, *prior; // 链表中各个结点的后继和前驱
    static StudentNode *pHead, *pTail;

public:
    // 构造函数
    StudentNode(char *name, int age, float score){
        this->id = 0;
        strcpy(this->name, name);
        this->age = age;
        this->score = score;
        this->next = NULL;
        this->prior = NULL;
    }

    // 添加学生结点
    static void AddSN(StudentNode* pSn){
        ID_buffer++;
        pSn->id = ID_buffer;
        if(pHead==NULL){
            pHead = pSn;
            // 双向链表中包含前驱和后继的信息，头尾结点在链表初始化时，属于同一结点。
            // 即前驱为NULL的头结点，后继为NULL的尾结点
            pTail = pHead;
            return;
        }
        pTail->next = pSn;  // 在尾结点后添加新结点，尾结点的后继指向新结点
        pSn->prior = pTail;  // 新结点的前驱指向原尾结点
        pTail = pSn; // 更新尾结点
    }

    // 根据id删除结点
    static bool DeleteSN(int id){
        if(pHead==NULL){
            return false;
        }
        StudentNode *pMove = pHead;
        while (pMove!=NULL){
            if(pMove->id==id){
                if(pMove->prior!=NULL){
                    pMove->prior->next = pMove->next; // 更新删除当前结点后前驱结点的后继结点
                }
                if(pMove->next!=NULL){
                    pMove->next->prior = pMove->prior; // 更新删除当前结点后后继结点的前驱结点
                }
                StudentNode * pTemp = pMove; // 保留删除结点处的内存
                pMove = pMove->next;  // 移动指针
                delete pTemp;

                // 学生编号前移
                while(pMove!=NULL){
                    pMove->id--;
                    pMove = pMove->next;  // 移动指针到下一位
                }
                ID_buffer--;  // 删除了一个id，总ID数减1
                return true;
            }

            pMove = pMove->next; // 前面没找到，继续遍历结点寻找id
        }
        return false;  // 所有结点都遍历了也没找到
    }

    // 插入结点
    static bool insert(int position, StudentNode * ins_sn){
        // 在链表最后加入结点
        if(position==ID_buffer+1){
            StudentNode::AddSN(ins_sn);
        }

        // 加入位置非最后但目前链表为空
        if(position>ID_buffer||pHead==NULL){
            return false;
        }

        StudentNode* pMove = pHead;
        for(int i=0; i<position-1; i++){
            pMove = pMove->next;
        }
        // 在头结点插入，前驱为空
        if(pMove==pHead){
            pHead = ins_sn;
        }
        // 前驱解链，和新结点建立关系
        else{
            pMove->prior->next = ins_sn;
            ins_sn->prior = pMove->prior;
        }

        // 后驱解链，与新结点建立关系
        pMove->prior = ins_sn;  // 当前结点pMove后移，pMove变为插入结点的后驱结点
        ins_sn->next = pMove;

        // 新结点的编号值和插入位置处的结点编号相同
        ins_sn->id = pMove->id;
        // 插入位置后面的学生结点编号值加1
        while(pMove!=NULL){
            pMove->id ++;
            pMove = pMove->next;
        }
        ID_buffer++;
        return true;
    }

    // 显示结点
    static void show_nodes(){
        if(pHead==NULL){
            cout << "学生链表为空" << endl;
            return;
        }

        StudentNode * pMove = pHead;
        cout << endl;
        while(pMove!=NULL){
            cout << "id: " << pMove->id
                << "\t姓名: " << pMove->name
                << "\t年龄:" << pMove->age
                << "\t成绩:" << pMove->score << endl;
            pMove = pMove->next;
        }
    }
}SN;

#endif //CHAPTER10__STUDENTNODE_H
