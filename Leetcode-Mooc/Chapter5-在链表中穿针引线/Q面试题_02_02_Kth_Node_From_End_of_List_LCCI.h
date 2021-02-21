//
// Created by shexuan on 2021/2/21.
//

#ifndef CHAPTER5__Q面试题_02_02_KTH_NODE_FROM_END_OF_LIST_LCCI_H
#define CHAPTER5__Q面试题_02_02_KTH_NODE_FROM_END_OF_LIST_LCCI_H

#include <stack>
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
     int kthToLast(ListNode* head, int k) {
         // 方法1：两次遍历
         int length=0;
         ListNode * dummyHead = head;
         while(dummyHead){
             length++;
             dummyHead = dummyHead->next;
         }
         int i=0, j=length-k+1, ret;
         while(i!=j){
             ret = head->val;
             head = head->next;
             ++i;
         }
         return ret;
     }
 };


class Solution2 {
public:
    int kthToLast(ListNode* head, int k) {
        // 方法2：双指针
        ListNode * fast = head;
        ListNode * slow = head;
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        int ret = slow->val;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            ret = slow->val;
        }

        return ret;
    }
};



#endif //CHAPTER5__Q面试题_02_02_KTH_NODE_FROM_END_OF_LIST_LCCI_H
