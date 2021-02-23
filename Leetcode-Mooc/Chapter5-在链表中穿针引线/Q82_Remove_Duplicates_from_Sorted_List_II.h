//
// Created by shexuan on 2021/2/22.
//

#ifndef CHAPTER5__Q82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define CHAPTER5__Q82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H


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
        ListNode * dummyHead = new ListNode(-101); // 已知head->val ∈ [-100, 100]
        dummyHead->next = head;
        ListNode * cur = dummyHead->next;
        ListNode * pre = dummyHead;  // pre始终慢cur一步
        while(cur && cur->next){ // 1->2->2->2->3->4
            if(cur->next && pre->next->val!=cur->next->val){
                pre = pre->next; // pre为1
                cur = cur->next; // cur第1个2
            }else{
                // 2->2->2->3->4;
                // pre->next->val 第1个2
                // cur->next->val 第2个2
                while(cur->next && pre->next->val==cur->next->val){
                    cur = cur->next;
                } // 退出循环时 2->3->4, cur==2
                pre->next = cur->next; // 因为当前cur其实是重复值的最后一个，pre值为1，其next为3
                cur = cur->next; // 此时pre值仍然为1, cur = 3;
                // 下一轮时pre->next->val(3)!=cur->next->val(4)
            }
        }

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;

        return ret;
    }
};
#endif //CHAPTER5__Q82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
