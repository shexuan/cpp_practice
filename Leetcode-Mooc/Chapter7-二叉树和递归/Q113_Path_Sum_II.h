//
// Created by shexuan on 2021/2/27.
//

#ifndef CHAPTER7__Q113_PATH_SUM_II_H
#define CHAPTER7__Q113_PATH_SUM_II_H

#include <queue>
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
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         // BFS, 利用队列
         vector<vector<int> > ret;
         if(!root) return ret;
         queue<pair<TreeNode*, pair<int, vector<int>>>> q; // 内层pair first=> 此前路径和，second=>路径结点
         q.push(make_pair(root, make_pair(0, vector<int>())));
         while(!q.empty()){
             int size_ = q.size();
             for(int i=0; i<size_; i++){
                 TreeNode * node = q.front().first;
                 int val = node->val;
                 int sum = val + q.front().second.first;
                 vector<int> v = q.front().second.second;
                 v.push_back(node->val);
                 q.pop();
                 if(sum==targetSum && !node->left && !node->right){
                     ret.push_back(vector<int>(v.begin(), v.end())); // 已无后续子结点，因此不用push子节点入栈
                 }else{
                     if(node->left)
                         q.push(make_pair(node->left, make_pair(sum, v)));
                     if(node->right)
                         q.push(make_pair(node->right, make_pair(sum, v)));
                 }
             }
         }

         return ret;
     }
 };


class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // DFS方法
        vector<vector<int>> ret;
        if(!root) return ret;
        dfs(root, targetSum, vector<int>(), ret);

        return ret;
    }

    void dfs(TreeNode * root, int res, vector<int> vPath, vector<vector<int>> & v){
        if(!root) return;

        res -= root->val;
        vPath.push_back(root->val);
        if(res==0 && !root->left && !root->right){ // 左右子节点都不存在，因此此结点为叶子结点
            v.push_back(vPath);
        }
        if(root->left) dfs(root->left, res, vPath, v);
        if(root->right) dfs(root->right, res, vPath, v);
    }
};
#endif //CHAPTER7__Q113_PATH_SUM_II_H
