//
// Created by shexuan on 2021/3/4.
//

#ifndef CHAPTER9__Q64_MINIMUM_PATH_SUM_H
#define CHAPTER9__Q64_MINIMUM_PATH_SUM_H

#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrow = grid.size(), ncol = grid[0].size();

        int memo[nrow][ncol];

        // base case，第一行
        memo[0][0] = grid[0][0];
        for(int i=1;i<ncol;i++){
            memo[0][i] = grid[0][i]+memo[0][i-1];
        }
        if(nrow==1) return memo[0][ncol-1];

        // base case, 第一列
        memo[1][0] = grid[1][0];
        for(int i=1;i<nrow;i++){
            memo[i][0] = grid[i][0]+memo[i-1][0];
        }
        if(ncol==1) return memo[nrow-1][0];

        // 剩余的行
        for(int r=1; r<nrow; r++){
            // 状态转移公式：当前位置最小值 = min(左边, 上面) + 当前位置的值
            for(int c=1; c<ncol; c++){
                memo[r][c] = min(memo[r-1][c], memo[r][c-1]) + grid[r][c];
            }
        }

        return memo[nrow-1][ncol-1];
    }
};

#endif //CHAPTER9__Q64_MINIMUM_PATH_SUM_H
