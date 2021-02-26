//
// Created by shexuan on 2021/2/25.
//

#ifndef CHAPTER6____Q199_BINARY_TREE_RIGHT_SIDE_VIEW_H
#define CHAPTER6____Q199_BINARY_TREE_RIGHT_SIDE_VIEW_H

#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
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
     vector<int> rightSideView(TreeNode* root) {
         // 使用广度优先搜索，每一层仅保留最右边的结点
         vector<int> ret;
         queue<TreeNode *> q;
         if(root) q.push(root);

         while(!q.empty()){
             int size_ = q.size();
             TreeNode* node;
             for(int i=0; i<size_; i++){
                 node = q.front();
                 q.pop();
                 if(node->left) q.push(node->left);
                 if(node->right) q.push(node->right);
             }
             ret.push_back(node->val);
         }

         return ret;
     }
 };

class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        // 深度优先搜索，每个结点先访问右结点再访问左节点
        vector<int> ret;
        int depth = 0;
        dfs(root, depth, ret);

        return ret;
    }

    void dfs(TreeNode *root, int depth, vector<int> &ret){
        if(!root) return;

        if(depth==ret.size()){  // 深度等于ret的数量说明当前层还没被访问过，因此当前是第一个最右边的结点
            ret.push_back(root->val);
        }
        depth++;
        dfs(root->right, depth, ret);
        dfs(root->left, depth, ret);
    }
};

#endif //CHAPTER6____Q199_BINARY_TREE_RIGHT_SIDE_VIEW_H
