//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q46_PERMUTATIONS_H
#define CHAPTER8__Q46_PERMUTATIONS_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int visited[nums.size()];
        for(int i=0;i<nums.size(); i++){
            visited[i] = false;
        }
        vector<vector<int>> ret;
        dfs(nums, vector<int>(), ret, visited);
        return ret;
    }
    // int start,
    void dfs(const vector<int>& nums, vector<int> path, vector<vector<int>> &res, int visited[]){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path, res, visited);
            // 回溯
            visited[i] = false;
            path.pop_back();
        }
    }
};

#endif //CHAPTER8__Q46_PERMUTATIONS_H
