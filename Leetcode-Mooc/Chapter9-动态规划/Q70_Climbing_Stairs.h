//
// Created by shexuan on 2021/3/4.
//

#ifndef CHAPTER9__Q70_CLIMBING_STAIRS_H
#define CHAPTER9__Q70_CLIMBING_STAIRS_H

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n, -1);
        // base case
        if(n==0 || n==1) return 1;
        memo[0] = 1; // 第一级台阶
        memo[1] = 2; // 第二级台阶两种走法

        for(int i=2;i<n;i++){
            // 状态转移公式
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n-1];
    }
};

#endif //CHAPTER9__Q70_CLIMBING_STAIRS_H
