//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q47_PERMUTATIONS_II_H
#define CHAPTER8__Q47_PERMUTATIONS_II_H

#include <vector>
using namespace std;


class Solution {
public:
    vector<int> visited;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited = vector<int>(nums.size(), false);
        vector<vector<int>> ret;
        vector<int> path;
        // path放外面不使用vector<int>() 直接在函数中初始化，然后pass by reference，能节省内存且提升大量运行速度
        dfs(nums, path, ret);
        return ret;
    }

    void dfs(const vector<int> &nums, vector<int> &path, vector<vector<int>> &res){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++){
            // 两种剪枝情况
            // (1) 当前数值已用过
            // (2) 前一数值等于当前数值且前一数值已用过, 此时再用一个只是交换两个重复值的位置，但是组合不变
            if(visited[i] || (i>0 && nums[i]==nums[i-1] && visited[i-1])){
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, res);
            path.pop_back();
            visited[i] = false;
        }
    }
};



















#endif //CHAPTER8__Q47_PERMUTATIONS_II_H
