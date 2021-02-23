//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER5__Q328_ODD_EVEN_LINKED_LIST_H
#define CHAPTER5__Q328_ODD_EVEN_LINKED_LIST_H

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode * evenNode = head;
        ListNode * oddNode = head->next;
        ListNode* oddHead = oddNode;
        while(oddNode && evenNode){
            if(oddNode)evenNode->next = oddNode->next;
            if(oddNode->next)oddNode->next = oddNode->next->next;
            // 这里必须保证evenNode最后一个值不为null，因为其最后一个值的next需要指向oddNode
            if(evenNode->next)evenNode = evenNode->next;
            oddNode = oddNode->next;
        }
        evenNode->next = oddHead;
        return head;
    }
};
#endif //CHAPTER5__Q328_ODD_EVEN_LINKED_LIST_H
