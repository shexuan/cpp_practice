//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q77_COMBINATIONS_H
#define CHAPTER8__Q77_COMBINATIONS_H

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if(n<=0 || k>n ) return ret;
        vector<int> path;
        dfs(1, k, n, path, ret);
        return ret;
    }

    void dfs(int start, const int &k, const int &n, vector<int> &path, vector<vector<int>> &res){
        if(path.size()==k){
            res.push_back(path);
            return;
        }

        for(int i=start; i<=n-(k-path.size())+1; i++){
            path.push_back(i);
            dfs(i+1, k, n, path, res);
            path.pop_back();
        }
    }
};
#endif //CHAPTER8__Q77_COMBINATIONS_H
