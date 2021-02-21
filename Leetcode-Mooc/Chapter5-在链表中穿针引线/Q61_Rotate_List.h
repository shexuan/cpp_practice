//
// Created by shexuan on 2021/2/21.
//

#ifndef CHAPTER5__Q61_ROTATE_LIST_H
#define CHAPTER5__Q61_ROTATE_LIST_H

#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        // 先遍历一遍计算链表长度
        ListNode * cur = head;
        int len=0;
        while(cur){
            len++;
            cur = cur->next;
        }

        k = k%len;  // 计算实际需要旋转的结点数量
        if(k==0){
            return head;
        }
        int mv_back = len-k-1;  // 往后移的次数
        cur = head;
        // 将指针移动到需要旋转的结点位置
        for(int i=0;i<mv_back;i++){
            cur = cur->next;
        }

        ListNode * ret = cur->next;
        ListNode * nHead = cur->next;  // new head
        // 找到需要旋转的那些结点
        while(nHead->next){
            nHead = nHead->next;
        }

        nHead->next = head;
        cur->next = NULL;

        return ret;
    }
};
#endif //CHAPTER5__Q61_ROTATE_LIST_H
