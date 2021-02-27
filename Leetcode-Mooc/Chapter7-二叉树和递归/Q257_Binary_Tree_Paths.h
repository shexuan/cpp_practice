//
// Created by shexuan on 2021/2/27.
//

#ifndef CHAPTER7__Q257_BINARY_TREE_PATHS_H
#define CHAPTER7__Q257_BINARY_TREE_PATHS_H

#include <vector>
#include <string>
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
     vector<string> binaryTreePaths(TreeNode* root) {
         // BFS方法, 与112题路径之和思路相同
         vector<string> ret;
         if(!root) return ret;
         queue<pair<TreeNode*, string> > q; // first=>当前结点，second=>之前结点路径
         q.push(pair<TreeNode*, string>(root, ""));

         while(!q.empty()){
             int size_ = q.size();
             for(int i=0; i<size_; i++){
                 TreeNode * node = q.front().first;
                 int val = node->val;
                 string path;
                 if(q.front().second!=""){
                     path = q.front().second + "->" + to_string(node->val);
                 }else{ // 第一个结点（root）他之前的路径问空字符串
                     path = to_string(node->val);
                 }
                 q.pop();
                 if(!node->left && !node->right){
                     // 子节点为null，因此不必push子节点如队列
                     ret.push_back(path);
                 }else{
                     if(node->left) q.push(pair<TreeNode*, string>(node->left, path));
                     if(node->right) q.push(pair<TreeNode*, string>(node->right, path));
                 }
             }
         }
         return ret;

     }
 };


class Solution2 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // DFS 方法
        vector<string> ret;
        if(!root) return ret;
        dfs(root, "", ret);

        return ret;
    }

    void dfs(TreeNode * root, string path, vector<string> &v){
        if(!root) return;

        // 添加当前结点
        if(path!=""){
            path = path + "->" + to_string(root->val);
        }else{ // 根节点
            path = to_string(root->val);
        }
        // 左右子节点均不存在，已到达叶子节点
        if(!root->left && !root->right) v.push_back(path);

        dfs(root->left, path, v);
        dfs(root->right, path, v);
    }
};
#endif //CHAPTER7__Q257_BINARY_TREE_PATHS_H
