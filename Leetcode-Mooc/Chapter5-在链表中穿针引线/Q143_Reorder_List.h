//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER5__Q143_REORDER_LIST_H
#define CHAPTER5__Q143_REORDER_LIST_H

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


// 寻找链表中点 + 链表逆序 + 合并链表
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode * rightHead = head; // 慢指针，每次走一步，快指针走完了，慢指针走到中点(后半段)
        ListNode * tmp = head;  // 快指针，每次走两步
        int mid = 0;
        while(tmp && tmp->next){  // 总数为偶数时，最后tmp为null，奇数时最后tmp->next为null
            tmp = tmp->next->next;
            rightHead = rightHead->next;
            mid++;
        }

        // 反转后半段链表
        ListNode * rightCur = reverseList(rightHead);
        ListNode * dummyHead = new ListNode(1, head);
        ListNode * cur = dummyHead; // 用来连接的指针
        // 连接前半段和后半段
        ListNode * leftCur = head;  // 当前要连接的偶数节点
        while(mid>0){
            // 以下几步的步骤不能乱变，不然会出错
            cur->next = leftCur;  // 连上左链表结点
            leftCur = leftCur->next;  // 左链表后移一位
            cur->next->next = rightCur; // 连上右链表
            rightCur = rightCur->next; // 右链表后移一位

            cur = cur->next->next; // cur刚刚连上了两个结点，因此后移两位
            mid--;
        }
        if(rightCur){  // 总数为奇数，后半段都出一个
            cur->next = rightCur;
            cur = cur->next;
        }
        cur->next = nullptr; // 将尾结点next置null

        ListNode * ret = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;

        // return ret;
    }

    ListNode * reverseList(ListNode * head){
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while(cur){
            ListNode * nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};

 class Solution2 {
 public:
     void reorderList(ListNode* head) {
         // 放入数组中然后取出来连接
         vector<ListNode *> v;
         int len = 0;
         while(head){
             v.push_back(head);
             head = head->next;
             len++;
         }
         int mid = len/2;
         bool odd = len%2;
         int i=0;
         ListNode * dummyHead = new ListNode(10);
         ListNode * cur = dummyHead;
         while(i<mid){
             // 每次处理两个结点
             cur->next = v[i];
             cur->next->next = v[len-i-1];
             cur = cur->next->next;
             i++;
         }
         if(odd){  // 奇数的话需要最后把中间结点加进来
             cur->next = v[mid];
             cur = cur->next;
         }
         cur->next = nullptr;

         ListNode * ret = dummyHead->next;
         delete dummyHead;
         dummyHead = nullptr;
     }
 };
#endif //CHAPTER5__Q143_REORDER_LIST_H
