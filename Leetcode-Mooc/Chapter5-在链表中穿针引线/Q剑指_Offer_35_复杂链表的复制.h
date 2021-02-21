//
// Created by shexuan on 2021/2/21.
//

#ifndef CHAPTER5__Q剑指_OFFER_35_复杂链表的复制_H
#define CHAPTER5__Q剑指_OFFER_35_复杂链表的复制_H

#include <string>

using  namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        // 分3步复制
        // (1)先复制结点val并整合在源链表中：A->A'->B->B'->C->C';
        // (2)复制random结点：由于中间多了一个重复值，因此原结点在后移时每次都要移动两次；
        // (3)断开源链表与复制的链表结点：A->A'->B->B'->C->C' => A->B->C, A'->B'->C'

        // (1) 整合源链表与复制结点
        Node * cur = head;
        while(cur){
            Node * copyNode = new Node(cur->val);
            copyNode->next = cur->next;
            cur->next = copyNode;  // 将新结点整合进源链表中
            cur = cur->next->next;  // A->A'->B => A -> B
        }

        // (2) 复制随机结点
        cur = head;
        while(cur){
            // 新结点->随机结点 = 旧结点->随机结点->下一结点（此结点也为新结点）
            if(cur->random){  // cur->random==null 时不用设置新结点的random;
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // (3) 断开源链表与复制的链表结点: A->A'->B->B'->C->C' => A->B->C, A'->B'->C'
        cur = head;                 //将链表一分为二
        Node *copyHead = head->next;
        Node *p = head->next;
        while(cur)
        {
            cur->next = cur->next->next;
            cur = cur->next;
            if(p->next) // 最后一个结点的next为null，因此这里需要判断，不然p->next->next会报错
            {
                p->next = p->next->next;
                p = p->next;
            }
        }

        return copyHead;
    }
};
#endif //CHAPTER5__Q剑指_OFFER_35_复杂链表的复制_H
