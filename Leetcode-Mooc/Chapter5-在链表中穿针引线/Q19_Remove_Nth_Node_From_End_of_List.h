//
// Created by shexuan on 2021/2/22.
//

#ifndef CHAPTER5__Q19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define CHAPTER5__Q19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){ // 题意n>=1, 只有一个节点必然返回空
            return nullptr;
        }
        ListNode * dummyHead = new ListNode(-1);
        ListNode * cur = dummyHead;
        cur->next = head;
        cur = cur->next;
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }

        cur = dummyHead;
        int i=0, k=len-n;  // 5-2=3
        while(i<k){  // 走到删除结点的上一个结点
            cur = cur->next;
            i++;
        }
        cur->next = cur->next->next;
        return dummyHead->next;

    }
};
#endif //CHAPTER5__Q19_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
