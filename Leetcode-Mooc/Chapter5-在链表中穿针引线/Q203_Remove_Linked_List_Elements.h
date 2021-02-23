//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER5__Q203_REMOVE_LINKED_LIST_ELEMENTS_H
#define CHAPTER5__Q203_REMOVE_LINKED_LIST_ELEMENTS_H



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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode * dummyHead = new ListNode(1, head);
        ListNode * cur = head;
        ListNode * pre = dummyHead;  // 使用两个指针一起移动能避免很多空节点判断问题
        while(cur){
            while(cur && cur->val==val) {
                cur = cur->next;
            }
            pre->next = cur;
            pre = pre->next;
            if(cur) cur = cur->next; // 最后一个cur已经是空了，没有next
        }

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return ret;
    }
};
#endif //CHAPTER5__Q203_REMOVE_LINKED_LIST_ELEMENTS_H
