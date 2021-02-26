//
// Created by shexuan on 2021/2/24.
//

#ifndef CHAPTER6____Q94_BINARY_TREE_INORDER_TRAVERSAL_H
#define CHAPTER6____Q94_BINARY_TREE_INORDER_TRAVERSAL_H


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


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 中序遍历，先访问左节点值，再访问自身值，最后访问右结点值
        vector<int> ret;
        inorderHelper(root, ret);

        return ret;
    }

    void inorderHelper(TreeNode * root, vector<int> &v){
        if(!root) return;

        // 先访问左节点
        inorderHelper(root->left, v);
        // 再访问自身值
        v.push_back(root->val);
        // 最后访问右结点
        inorderHelper(root->right, v);
    }
};

// 迭代 + 栈 解法
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode * cur = root;

        while(cur || !stk.empty()){
            // 先将左节点全部入栈
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            // 这里到达了左节点最底部，也即递归时候的最上面, 访问当前结点值
            TreeNode * node = stk.top();
            stk.pop();
            ret.push_back(node->val);

            // 访问右结点
            if(node->right) cur = node->right;
        }

        return ret;
    }
};

#endif //CHAPTER6____Q94_BINARY_TREE_INORDER_TRAVERSAL_H
