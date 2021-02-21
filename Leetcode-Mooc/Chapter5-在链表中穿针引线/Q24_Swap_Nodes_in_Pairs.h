//
// Created by shexuan on 2021/2/22.
//

#ifndef CHAPTER5__Q24_SWAP_NODES_IN_PAIRS_H
#define CHAPTER5__Q24_SWAP_NODES_IN_PAIRS_H

#include <vector>
using  namespace std;

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummyHead = new ListNode(-1);
        ListNode * cur = dummyHead;

        int i=0;
        while(head && head->next){  // 两个才需要交换
            ListNode * node1 = head;
            ListNode * node2 = head->next;
            head = head->next->next;  // 先将head 指到下一个正确的位置，前面的两个结点指针就可以随便指了

            cur->next = node2;
            cur->next->next = node1;

            cur = cur->next->next; // cur 每一下也是跳两个
        }

        if(head) {  // 结点总数为单数的时候, 需要加上最后一个结点
            cur->next = head;
            cur = cur->next;
        }
        if(cur->next)cur->next = NULL;  // 双数时候交换后，结尾指针next不为NULL，需要手动置NULL

        return dummyHead->next;
    }
};

#endif //CHAPTER5__Q24_SWAP_NODES_IN_PAIRS_H
