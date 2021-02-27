//
// Created by shexuan on 2021/2/27.
//

#ifndef CHAPTER7__Q129_SUM_ROOT_TO_LEAF_NUMBERS_H
#define CHAPTER7__Q129_SUM_ROOT_TO_LEAF_NUMBERS_H

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
    int sumNumbers(TreeNode *root) {
        // BFS 前序遍历先求出所有路径，然后求和
        long ret = 0;
        vector<vector<int> > vPath;
        if (!root) return 0;
        queue<pair<TreeNode *, vector<int>>> q;
        q.push(make_pair(root, vector<int>()));
        while (!q.empty()) {
            int size_ = q.size();
            for (int i = 0; i < size_; i++) {
                TreeNode *node = q.front().first;
                vector<int> v = q.front().second;
                v.push_back(node->val);
                q.pop();
                if (!node->left && !node->right) vPath.push_back(v);
                if (node->left) q.push(make_pair(node->left, v));
                if (node->right) q.push(make_pair(node->right, v));
            }
        }

        for (auto &v: vPath) {
            ret += path2num(v);
        }

        return ret;
    }

    int path2num(vector<int> v) {
        long num = 0;
        long rate = 1;
        while (!v.empty()) {
            long tmp = v.back();
            num += tmp * rate;
            rate *= 10;
            v.pop_back();
        }
        return num;
    }
};


class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        // DFS 深度优先遍历
        if (!root) return 0;

        vector<vector<int>> paths = {};
        dfs(root, vector<int>(), paths);

        long ret = 0;
        for (auto &v: paths) {
            ret += path2num(v);
        }

        return ret;
    }

    void dfs(TreeNode *root, vector<int> vPath, vector<vector<int>> &v) {
        if (!root) return;
        vPath.push_back(root->val);
        // 判断叶子结点
        if (!root->left && !root->right) {
            v.push_back(vPath);
        }
        if (root->left) dfs(root->left, vPath, v);
        if (root->right) dfs(root->right, vPath, v);
    }

    int path2num(vector<int> v) {
        long num = 0;
        long rate = 1;
        while (!v.empty()) {
            long tmp = v.back();
            num += tmp * rate;
            rate *= 10;
            v.pop_back();
        }
        return num;
    }
};


// 大佬代码
class Solution3 {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        return sumHelper(root, 0);
    }

    int sumHelper(TreeNode *root, long sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;

        return sumHelper(root->left, sum) + sumHelper(root->right, sum);
    }
};


#endif //CHAPTER7__Q129_SUM_ROOT_TO_LEAF_NUMBERS_H
