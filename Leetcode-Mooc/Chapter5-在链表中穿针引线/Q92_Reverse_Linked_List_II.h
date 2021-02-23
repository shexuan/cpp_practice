//
// Created by shexuan on 2021/2/22.
//

#ifndef CHAPTER5__Q92_REVERSE_LINKED_LIST_II_H
#define CHAPTER5__Q92_REVERSE_LINKED_LIST_II_H


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummyHead = new ListNode(-1);
        ListNode * cur = dummyHead;
        cur->next = head;
        int i=0;
        while(i<left-1 && cur){
            cur = cur->next;
            i++;
        }

        /*  pre  cur   next
         * A  ->  B  ->  C -> D -> E
         * 其中BCD为需要交换的结点
         */
        ListNode *cur2 = cur->next;
        i++; // 后面用cur2来迭代，所以这里+1
        ListNode *revBeg = cur->next; // 需要交换的头结点，这个头结点在交换后一直处于交换区结尾
        ListNode * pre = nullptr; // 当要交换结点为B-C时，pre为NULL
        while(i<=right && cur2){
            ListNode * nxt = cur2->next;
            cur2->next = pre;
            pre = cur2;
            cur2 = nxt;
            i++;
        }

        revBeg->next = cur2;
        cur->next = pre;

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return ret;
    }
};
#endif //CHAPTER5__Q92_REVERSE_LINKED_LIST_II_H
