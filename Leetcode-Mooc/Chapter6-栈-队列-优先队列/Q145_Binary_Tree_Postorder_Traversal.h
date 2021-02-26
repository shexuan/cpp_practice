//
// Created by shexuan on 2021/2/24.
//

#ifndef CHAPTER6____Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H
#define CHAPTER6____Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H

#include <vector>
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
     vector<int> postorderTraversal(TreeNode* root) {
         // 先遍历左节点，在遍历右结点，左右遍历当前节点值
         vector<int> ret;
         postorderHelper(root, ret);

         return ret;
     }

     void postorderHelper(TreeNode * root, vector<int> & v){
         if(!root) return;
         // 先遍历左节点
         postorderHelper(root->left, v);
         // 再遍历右结点
         postorderHelper(root->right, v);
         // 获取当前结点的值
         v.push_back(root->val);
     }
 };


class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // 先遍历左节点，在遍历右结点，左右遍历当前节点值
        vector<int> ret;
        if(!root) return ret;

        // 前序遍历的过程 是 中左右。
        // 将其转化成 中右左。也就是压栈的过程中优先压入左子树，在压入右子树。
        // 然后将这个结果返回来，这里是利用栈的先进后出倒序打印。
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        stk1.push(root);
        while(!stk1.empty()){
            TreeNode * node = stk1.top();
            stk1.pop();
            stk2.push(node);

            if(node->left) stk1.push(node->left);
            if(node->right) stk1.push(node->right);
        }

        while(!stk2.empty()){
            ret.push_back(stk2.top()->val);
            stk2.pop();
        }

        return ret;
    }
};

// 作者：gre-z
// 链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




#endif //CHAPTER6____Q145_BINARY_TREE_POSTORDER_TRAVERSAL_H
