//
// Created by shexuan on 2021/2/21.
//

#ifndef CHAPTER5__Q445_ADD_TWO_NUMBERS_II_H
#define CHAPTER5__Q445_ADD_TWO_NUMBERS_II_H

#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        // 先将两个链表的数值都放入到栈中然后进行相加
        stack<int> s1;
        stack<int> s2;

        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        int sum;
        ListNode * ret = NULL;
        while(!s1.empty() || !s2.empty() || carry!=0){
            int i1 = s1.empty()?0:s1.top();
            int i2 = s2.empty()?0:s2.top();
            sum = i1 + i2 + carry;
            carry = sum/10;
            ListNode * cur = new ListNode(sum%10);
            cur->next = ret;
            ret = cur;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }

        return ret;
    }
};


#endif //CHAPTER5__Q445_ADD_TWO_NUMBERS_II_H
