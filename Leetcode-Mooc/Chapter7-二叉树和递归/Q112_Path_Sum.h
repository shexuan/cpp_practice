//
// Created by shexuan on 2021/2/27.
//

#ifndef CHAPTER7__Q112_PATH_SUM_H
#define CHAPTER7__Q112_PATH_SUM_H

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
     bool hasPathSum(TreeNode* root, int targetSum) {
// DFS方法
         // 注意审题：root-leaf
         if(!root) return false;
         return _pathSum(root, targetSum);
     }

     bool _pathSum(TreeNode *root, int res){
         if(!root) return false;
         if(!root->left && !root->right){  // 左右节点均为nullptr才是叶结点
             return res==root->val;
         }

         return _pathSum(root->left, res-root->val) || _pathSum(root->right, res-root->val);
     }
 };

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        // 借助队列的BFS方法
        queue<pair<TreeNode*, int> > q; // first=> 结点，second=>之前路径结点的和
        q.push(pair<TreeNode*, int>(root, 0));
        while(!q.empty()){
            int size_ = q.size();
            for(int i=0; i<size_; i++){
                TreeNode * node = q.front().first;
                int pSum = q.front().second+node->val;
                q.pop();
                if(!node->left && !node->right && pSum==targetSum) return true;
                if(node->left) q.push(pair<TreeNode*, int>(node->left, pSum));
                if(node->right) q.push(pair<TreeNode*, int>(node->right, pSum));
            }
        }

        return false;
    }
};
#endif //CHAPTER7__Q112_PATH_SUM_H
