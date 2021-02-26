//
// Created by shexuan on 2021/2/25.
//

#ifndef CHAPTER6____Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
#define CHAPTER6____Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        queue<TreeNode *> q;
        bool l2r=true;  // left to right, 每换一层方向交换下
        if(root) q.push(root);

        while(!q.empty()){
            int size_ = q.size();
            ret.push_back(vector<int> ());
            for(int i=0; i<size_; i++){
                TreeNode * node = q.front();
                q.pop();
                if(l2r){  // left->right
                    ret.back().push_back(node->val);
                }else{  // right->left 时候在前面插入
                    ret.back().insert(ret.back().begin(), node->val);
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            l2r = l2r?false:true;
        }
        return ret;
    }
};
#endif //CHAPTER6____Q103_BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_H
