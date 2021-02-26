//
// Created by shexuan on 2021/2/25.
//

#ifndef CHAPTER6____Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define CHAPTER6____Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 广度优先搜索
        vector<vector<int> > ret;
        queue<TreeNode *> q;  // 先进先出
        if(root) q.push(root);

        while(!q.empty()){
            int size_ = q.size();
            // 每一次while循环都将本层中所有结点遍历完
            vector<int> lv;
            for(int i=0; i<size_; i++){
                TreeNode * node = q.front();
                q.pop();
                lv.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(lv);
        }

        return ret;
    }
};

#endif //CHAPTER6____Q102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
