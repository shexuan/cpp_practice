//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER5__Q876_MIDDLE_OF_THE_LINKED_LIST_H
#define CHAPTER5__Q876_MIDDLE_OF_THE_LINKED_LIST_H

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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
#endif //CHAPTER5__Q876_MIDDLE_OF_THE_LINKED_LIST_H
