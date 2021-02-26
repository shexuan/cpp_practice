//
// Created by shexuan on 2021/2/24.
//

#ifndef CHAPTER6____Q144_BINARY_TREE_PREORDER_TRAVERSAL_H
#define CHAPTER6____Q144_BINARY_TREE_PREORDER_TRAVERSAL_H

#include <vector>
#include <stack>

using namespace std;

// 二叉树遍历讲解： https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
// https://segmentfault.com/a/1190000016674584

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 递归方法遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderHelper(root, ret);
        return ret;
    }

    void preorderHelper(TreeNode * root, vector<int> & v){
        if(!root) return;  // null 直接返回
        // 添加当前结点的值
        v.push_back(root->val);
        // 访问左节点
        preorderHelper(root->left, v);
        // 访问右结点
        preorderHelper(root->right, v);
    }
};


// 迭代 + 栈 方法遍历
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ret;

        stk.push(root);
        TreeNode * cur;
        while(!stk.empty()){
            cur = stk.top(); // 获取当前结点的值
            if(cur) ret.push_back(cur->val);
            stk.pop(); // 弹出当前结点；
            if(cur)stk.push(cur->right); // 先将右结点压入栈，因为是前序遍历，需要先访问左节点
            if(cur)stk.push(cur->left);  // 左节点压入栈，后进先出
        }

        return ret;
    }
};
#endif //CHAPTER6____Q144_BINARY_TREE_PREORDER_TRAVERSAL_H
