//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q216_COMBINATION_SUM_III_H
#define CHAPTER8__Q216_COMBINATION_SUM_III_H

#include <vector>
#include <string>

using namespace std;

# include <algorithm>
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        if(n>k*9 || n<k*1) return ret;

        vector<int> path;
        dfs(1, n, k, path, ret);

        return ret;
    }

    void dfs(int start, int num, const int &k, vector<int> &path, vector<vector<int>> &ret){
        if(num==0 && path.size()==k){
            ret.push_back(path);
            return;
        }
        for(int i=start; i<10; i++){
            // (1) path中的数少于k个；(2)至少要大于等于0，才能继续放进去数
            if((path.size()>k) || (num-i<0)) break;
            path.push_back(i);
            dfs(i+1, num-i, k, path, ret);
            path.pop_back();
        }
    }
};

#endif //CHAPTER8__Q216_COMBINATION_SUM_III_H
