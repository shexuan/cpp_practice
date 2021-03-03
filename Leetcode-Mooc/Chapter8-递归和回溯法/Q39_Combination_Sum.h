//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q39_COMBINATION_SUM_H
#define CHAPTER8__Q39_COMBINATION_SUM_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        if(candidates[0]>target) return ret;
        vector<int> path;
        dfs(0, target, candidates, path, ret);

        return ret;
    }

    void dfs(int start, int num, vector<int> &candidates, vector<int> &path, vector<vector<int>> &res){
        if(num==0){
            res.push_back(path);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(num-candidates[i]>=0){ // 差大于0，说明还能放数字
                path.push_back(candidates[i]);
                dfs(i, num-candidates[i], candidates, path, res);
                path.pop_back();
            }else{ // 差大于0，说明当前数字组合已经大于target，且由于排序原因，越往后组合只会越大，因此可以直接退出
                break;
            }
        }
    }
};


#endif //CHAPTER8__Q39_COMBINATION_SUM_H
