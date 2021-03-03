//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q90_SUBSETS_II_H
#define CHAPTER8__Q90_SUBSETS_II_H


#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        dfs(0, nums, visited, path, ret);
        return ret;
    }

    void dfs(int start, const vector<int> &nums, vector<bool> &visited, vector<int> &path, vector<vector<int>> &ret){
        if(start>nums.size()) return;
        ret.push_back(path);

        for(int i=start; i<nums.size(); i++){
            // 当前与前一个相等且前一个没有访问过，说明是回溯到了这一层，若使用这个值只会产生重复的组合
            // 若是前一个想同值访问过了，则表示的是递归的上一层访问的
            if(i>0 && nums[i-1]==nums[i] && !visited[i-1]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(i+1, nums, visited, path, ret);
            path.pop_back();
            visited[i] = false;
        }

    }
};

#endif //CHAPTER8__Q90_SUBSETS_II_H
