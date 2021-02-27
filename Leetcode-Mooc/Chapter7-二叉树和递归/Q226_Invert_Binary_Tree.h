//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q226_INVERT_BINARY_TREE_H
#define CHAPTER7__Q226_INVERT_BINARY_TREE_H

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
#endif //CHAPTER7__Q226_INVERT_BINARY_TREE_H
