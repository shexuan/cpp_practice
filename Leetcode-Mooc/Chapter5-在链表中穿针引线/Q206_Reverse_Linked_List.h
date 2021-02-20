//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER5__Q206_REVERSE_LINKED_LIST_H
#define CHAPTER5__Q206_REVERSE_LINKED_LIST_H


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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){ // list为空或只有一个元素
            return head;
        }
        ListNode * pre = nullptr;
        ListNode * cur = head;

        /*  pre   cur    next
         *  null   1  ->   2  ->  3  ->  4  ->  5 -> null
         *
         *  处理一位后(即交换1、2位置后):
         *           pre   cur     next
         *  null  <-  1     2   ->   3   ->  4 ->  5 -> null
         *
         *  while循环最后一步（cur==null）：
         *                                           pre   cur     next
         *  null  <-  1   <-  2   <-   3   <-  4  <-  5    null
         *
         */

        while (cur){
            ListNode * next = cur->next;
            cur->next = pre;  //
            pre = cur;
            cur = next;
        }

        return pre;
    }
};
#endif //CHAPTER5__Q206_REVERSE_LINKED_LIST_H
