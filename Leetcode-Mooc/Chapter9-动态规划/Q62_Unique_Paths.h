//
// Created by shexuan on 2021/3/5.
//

#ifndef CHAPTER9__Q62_UNIQUE_PATHS_H
#define CHAPTER9__Q62_UNIQUE_PATHS_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 特例
        if(m==1 || n==1) return 1;

        // base case, 第一行第一列均只有一种走法，初始化为1
        vector<vector<int> > memo(m, vector<int>(n,1));

        for(int r=1;r<m;r++){
            for(int c=1;c<n;c++){
                // 状态转移公式: 每一个位置可由上方或者左方移动得到
                memo[r][c] = memo[r-1][c]+memo[r][c-1];
            }
        }

        return memo[m-1][n-1];
    }
};


 class Solution2 {
 public:
     int uniquePaths(int m, int n) {
         vector<int> vec(m, 1);//m列的向量
         for(int i = 0; i < n - 1; i++)//n行，就要迭代n-1次
             for(int j = 1; j < m; j++)
                 vec[j] += vec[j-1];
         return vec[m-1];
     }
 };


#endif //CHAPTER9__Q62_UNIQUE_PATHS_H
