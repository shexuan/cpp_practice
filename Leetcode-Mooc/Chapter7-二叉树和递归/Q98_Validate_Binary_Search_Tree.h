//
// Created by shexuan on 2021/2/28.
//

#ifndef CHAPTER7__Q98_VALIDATE_BINARY_SEARCH_TREE_H
#define CHAPTER7__Q98_VALIDATE_BINARY_SEARCH_TREE_H

#include <vector>
#include <string>
#include <queue>
#include <stack>
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
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        // DFS
        // 利用搜索二叉树性质：中序遍历结果为升序序列
        if(!root) return true;

        if(!isValidBST(root->left)) return false;

        if(root->val<=pre) return false;
        pre = root->val;

        return isValidBST(root->right);
    }
};


 class Solution2 {
 public:
     bool isValidBST(TreeNode* root) {
         // 迭代法
         // 利用搜索二叉树性质：中序遍历结果为升序序列
         // 中序遍历：先访问左节点，再访问当前结点，最后访问右结点
         if(!root) return false;
         if(!root->left && !root->right) return true;
         stack<TreeNode*> stk;
         vector<int> v;
         TreeNode * cur = root;
         while(cur || !stk.empty()){
             // 先找到最左子结点, 栈后入先出
             while(cur){
                 stk.push(cur);
                 cur = cur->left;
             }

             // 栈后入先出, 最底左节点
             TreeNode *node = stk.top();
             stk.pop();
             v.push_back(node->val);

             // 若此最左结点有右子结点的话，还需把这个右子结点的话，还需要递归的把它们的右子结点全部访问掉；
             if(node->right) cur = node->right;
         }

         for(int i=1;i<v.size(); i++){
             if(v[i]<=v[i-1]) return false;
         }

         return true;
     }
 };
#endif //CHAPTER7__Q98_VALIDATE_BINARY_SEARCH_TREE_H
