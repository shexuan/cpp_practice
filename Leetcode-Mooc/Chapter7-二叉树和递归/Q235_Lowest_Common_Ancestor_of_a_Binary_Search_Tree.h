//
// Created by shexuan on 2021/2/28.
//

#ifndef CHAPTER7__Q235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
#define CHAPTER7__Q235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H

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


// 根据二叉搜索树性质：如果 p.val 和 q.val 都比 root.val 小，则 p、q 肯定在 root 的左子树。
// 那问题规模就变小了，递归左子树就行！
// 如果 p.val 和 q.val 都比 root.val 大，递归右子树就行！
// 其他情况，root 即为所求！
//
// 作者：xiao_ben_zhu
// 链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solution/di-gui-he-die-dai-fa-by-hyj8/

 class Solution {
 public:
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // 迭代法
         if(!root) return nullptr;
         TreeNode * cur = root;
         while(cur){
             // p、q都小于cur, 因此pq均在左侧子树中
             if(cur->val>q->val && cur->val>p->val){
                 cur = cur->left;
             }else if(cur->val<p->val && cur->val<q->val){ // p、q都大于cur, 因此pq均在右侧子树中
                 cur = cur->right;
             }else{ // p、q在cur两侧，或p q等于cur
                 break;
             }
         }

         return cur;
     }
 };

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // DFS
        if(!root) return nullptr;
        if(root->val>p->val && root->val>q->val){
            root = root->left;
            return lowestCommonAncestor(root, p, q);
        }else if(root->val<p->val && root->val<q->val){
            root = root->right;
            return lowestCommonAncestor(root, p, q);
        }

        return root;

    }

};
#endif //CHAPTER7__Q235_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
