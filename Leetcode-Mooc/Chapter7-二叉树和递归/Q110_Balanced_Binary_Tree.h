//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q110_BALANCED_BINARY_TREE_H
#define CHAPTER7__Q110_BALANCED_BINARY_TREE_H

#include <vector>
using namespace std;

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        return maxDepth(root)!=-100;
    }

    int maxDepth(TreeNode * root){
        if(!root) return 0;

        int rightDep = maxDepth(root->right);
        if(rightDep==-100) return -100; // 若左子树不平衡，直接返回 -100

        int leftDep = maxDepth(root->left);
        if(leftDep==-100) return -100;  // 若右子树不平衡，直接返回 -100

        if(abs(rightDep-leftDep)>1) return -100;  // 若左右子树不平衡，直接返回 -100

        return max(rightDep, leftDep) + 1;
    }
};
#endif //CHAPTER7__Q110_BALANCED_BINARY_TREE_H
