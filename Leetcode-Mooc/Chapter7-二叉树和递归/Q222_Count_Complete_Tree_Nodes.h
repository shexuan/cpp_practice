//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q222_COUNT_COMPLETE_TREE_NODES_H
#define CHAPTER7__Q222_COUNT_COMPLETE_TREE_NODES_H

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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // int dfs(TreeNode *root, int &n){
    //     if(!root) return 0;
    //     n++;
    //     dfs(root->left, n);
    //     dfs(root->right, n);

    //     return n;
    // }
};
#endif //CHAPTER7__Q222_COUNT_COMPLETE_TREE_NODES_H
