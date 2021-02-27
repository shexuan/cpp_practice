//
// Created by shexuan on 2021/2/25.
//

#ifndef CHAPTER7__Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define CHAPTER7__Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include <queue>

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
     int maxDepth(TreeNode* root) {
         // 深度优先，递归
         if(!root) return 0;
         return max(maxDepth(root->left), maxDepth(root->right))+1;
     }
 };

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        // 利用广度搜索的思路来做
        int ret = 0;
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            int size_ = q.size();
            for(int i=0; i<size_; i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret++;
        }

        return ret;
    }
};
#endif //CHAPTER7__Q104_MAXIMUM_DEPTH_OF_BINARY_TREE_H
