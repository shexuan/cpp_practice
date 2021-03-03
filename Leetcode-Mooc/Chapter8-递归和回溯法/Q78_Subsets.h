//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q78_SUBSETS_H
#define CHAPTER8__Q78_SUBSETS_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()==0) return ret;

        vector<int> path;
        dfs(0, nums, path, ret);
        return ret;
    }

    void dfs(int start, const vector<int> &nums, vector<int> &path, vector<vector<int>> &ret){
        if(start>nums.size()) return;
        ret.push_back(path);

        for(int i=start; i<nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i+1, nums, path, ret);
            path.pop_back();
        }
    }
};
#endif //CHAPTER8__Q78_SUBSETS_H
