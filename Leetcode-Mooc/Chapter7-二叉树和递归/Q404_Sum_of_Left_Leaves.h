//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER7__Q404_SUM_OF_LEFT_LEAVES_H
#define CHAPTER7__Q404_SUM_OF_LEFT_LEAVES_H

#include <queue>
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
     int sumOfLeftLeaves(TreeNode* root) {
         // DFS写法
         if(!root) return 0;
         int ret = 0;
         leftSum(root, ret);
         return ret;
     }

     void leftSum(TreeNode * root, int &n){
         if(!root) return;
         if(root->left && !root->left->left && !root->left->right){
             n += root->left->val;  // 条件执行完不用返回，因为root->right右结点可能还有左子节点可以继续加进来
         }

         leftSum(root->left, n);
         leftSum(root->right, n);
     }
 };


class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // BFS写法，使用队列或栈皆可
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ret=0;

        while(!q.empty()){
            int size_ = q.size();
            for(int i=0; i<size_; i++){
                TreeNode * node = q.front();
                q.pop();
                // 左子节点没有左右节点，说明他是个左叶子
                if(node->left && !node->left->left && !node->left->right){
                    ret += node->left->val;
                    if(node->right) q.push(node->right);  // 这时候左节点就不用push入队了，因为左节点是个叶子节点
                }else{
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }

        return ret;
    }
};
#endif //CHAPTER7__Q404_SUM_OF_LEFT_LEAVES_H
