//
// Created by shexuan on 2021/2/21.
//

#ifndef CHAPTER5__Q21_MERGE_TWO_SORTED_LISTS_H
#define CHAPTER5__Q21_MERGE_TWO_SORTED_LISTS_H


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 与归并排序的merge思路基本相同
        ListNode * dummyHead = new ListNode(-101);
        ListNode * cur = dummyHead;
        while(l1 && l2){
            if(l1->val<=l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        while(l1){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        return dummyHead->next;
    }
};
#endif //CHAPTER5__Q21_MERGE_TWO_SORTED_LISTS_H
