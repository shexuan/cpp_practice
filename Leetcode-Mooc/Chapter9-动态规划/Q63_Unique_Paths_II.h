//
// Created by shexuan on 2021/3/5.
//

#ifndef CHAPTER9__Q63_UNIQUE_PATHS_II_H
#define CHAPTER9__Q63_UNIQUE_PATHS_II_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nrow = obstacleGrid.size(), ncol = obstacleGrid[0].size();
        // 特例1，机器人出发位置就是石头
        if(obstacleGrid[0][0]==1) return 0;
        // 特例2，仅一行或一列
        if(ncol==1 || nrow==1){
            for(int r=0;r<nrow;r++){
                for(int c=0;c<ncol;c++)
                    if(obstacleGrid[r][c]==1) return 0;
            }

            return 1;
        }

        vector<vector<int> > memo(nrow, vector<int>(ncol, 0));
        // base case，首行首列，只要没碰到1，那么走法都为1，碰到了1后面的走法都为0
        memo[0][0] = 1;
        for(int i=1;i<ncol;i++){ // 填充首行
            if(obstacleGrid[0][i]!=1){
                memo[0][i] = memo[0][i]+memo[0][i-1];
            }else{
                memo[0][i] = 0;
            }
        }

        for(int i=1;i<nrow;i++){  // 填充首列
            if(obstacleGrid[i][0]!=1){
                memo[i][0] = memo[i][0]+memo[i-1][0];
            }else{
                memo[i][0] = 0;
            }
        }

        for(int r=1;r<nrow;r++){
            for(int c=1;c<ncol;c++){
                if(obstacleGrid[r][c]==1){ // 障碍物，此路不通
                    memo[r][c] = 0;
                }else{
                    memo[r][c] = memo[r-1][c]+memo[r][c-1];
                }
                // cout << memo[r][c] << endl;
            }
        }

        return memo[nrow-1][ncol-1];
    }
};

#endif //CHAPTER9__Q63_UNIQUE_PATHS_II_H
