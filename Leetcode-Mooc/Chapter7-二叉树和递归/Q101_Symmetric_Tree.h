//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q101_SYMMETRIC_TREE_H
#define CHAPTER7__Q101_SYMMETRIC_TREE_H

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;

        return _symmetric(root, root);
    }

    bool _symmetric(TreeNode * leftNode, TreeNode *rightNode){
        if(!leftNode && !rightNode) return true;

        if(leftNode==nullptr || rightNode==nullptr) return false;

        if(leftNode->val!=rightNode->val) return false;

        return _symmetric(leftNode->left, rightNode->right) && _symmetric(leftNode->right, rightNode->left);
    }
};
#endif //CHAPTER7__Q101_SYMMETRIC_TREE_H
