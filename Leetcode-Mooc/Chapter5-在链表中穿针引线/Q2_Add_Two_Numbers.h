//
// Created by shexuan on 2021/2/22.
//

#ifndef CHAPTER5__Q2_ADD_TWO_NUMBERS_H
#define CHAPTER5__Q2_ADD_TWO_NUMBERS_H

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode * dummyHead = new ListNode(-1);
        ListNode * cur = dummyHead;
        while(l1 || l2 || carry!=0){
            int i1 = l1?l1->val:0;
            int i2 = l2?l2->val:0;
            sum = i1+i2+carry;
            carry = sum/10;
            // cout << "i1=" << i1 << " i2="<< i2 << " sum=" << sum << endl;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;

        return ret;
    }
};
#endif //CHAPTER5__Q2_ADD_TWO_NUMBERS_H
