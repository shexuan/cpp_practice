//
// Created by shexuan on 2021/2/27.
//

#ifndef CHAPTER7__Q437_PATH_SUM_III_H
#define CHAPTER7__Q437_PATH_SUM_III_H

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
    int cunt = 0;
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;

        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);

        return cunt;
    }

    void dfs(TreeNode* root, int res){
        if(!root) return;
        res -= root->val;
        if(res==0) cunt++;

        if(root->left) dfs(root->left, res);
        if(root->right) dfs(root->right, res);
    }
};
#endif //CHAPTER7__Q437_PATH_SUM_III_H
