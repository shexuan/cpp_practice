//
// Created by shexuan on 2021/2/10.
//

#ifndef CHAPTER12__SIMPLELIST_H
#define CHAPTER12__SIMPLELIST_H

#include <iostream>
#include <string>

using namespace std;

class CNode{  // 定义一个节点类
public:
    CNode *m_pNext;  // 定义一个结点指针，指向下一个结点
    int m_Data;  // 定义结点的数据
    CNode(){   // 定义结点类的构造函数
        m_pNext = NULL;
    }

    explicit CNode(int data){   // 定义结点类的构造函数
        m_pNext = NULL;
        m_Data = data;
    }
};


class CList{  // 定义链表类CList
private:
    CNode *m_pHeader; // 定义头结点
    int m_NodeSum;  // 结点数量

public:
    CList(){
        m_pHeader = NULL;
        m_NodeSum = 0;
    }

    CNode* MoveTrail(){  // 移动到尾结点
        CNode * pTmp = m_pHeader;
        for(int i=1; i<m_NodeSum; i++){
            pTmp = pTmp->m_pNext;  // 获取下一个结点
        }
        return pTmp;   // 返回尾结点
    }

    void AddNode(CNode *pNode){  // 添加结点
        if(m_NodeSum==0){
            m_pHeader = pNode;
        }else{
            CNode * pTail = MoveTrail();
            pTail->m_pNext = pNode;   // 在尾结点处添加结点
        }
        m_NodeSum++;
    }

    void PassList(){   // 遍历列表
        if(m_NodeSum>0){  // 判断链表是否为空
            CNode *pTmp = m_pHeader;
            for (int i=0; i<m_NodeSum; i++){
                cout << pTmp->m_Data << " -> ";
                pTmp = pTmp->m_pNext;
            }
            cout << endl;
        }else{
            cout << "链表为空!" << endl;
        }
    }

    ~CList(){   // 链表析构函数
        if(m_NodeSum>0){
            CNode *pDelete = m_pHeader;
            CNode *pTmp = NULL;
            for(int i=0; i<m_NodeSum; i++){
                pTmp = pDelete->m_pNext;
                delete pDelete;
                pDelete = pTmp;
            }
            m_NodeSum = 0;
            pDelete = NULL;
            pTmp = NULL;
        }
        m_pHeader = NULL;
    }
};

#endif //CHAPTER12__SIMPLELIST_H




















