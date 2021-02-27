//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q100_SAME_TREE_H
#define CHAPTER7__Q100_SAME_TREE_H

using  namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;  // 两者都为null

        if(p==nullptr || q==nullptr) return false;  // 其中一个为null

        if(p->val!=q->val) return false; // { // p、q都不为null且其值相等

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

#endif //CHAPTER7__Q100_SAME_TREE_H
