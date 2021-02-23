//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER5__Q83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define CHAPTER5__Q83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode * dummyHead = head;
        ListNode * pre = head;
        ListNode * cur = head->next;
        while(cur){
            while(cur && pre->val==cur->val){
                cur = cur->next;
            }
            pre->next = cur;
            pre = pre->next;
            if(cur) cur = cur->next; // 如 1->1, 最后cur直接指到null了，因此需要判断当前是否为null
        }
        return dummyHead;
    }
};
#endif //CHAPTER5__Q83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
