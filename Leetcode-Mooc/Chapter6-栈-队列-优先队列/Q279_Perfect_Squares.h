//
// Created by shexuan on 2021/2/26.
//

#ifndef CHAPTER6____Q279_PERFECT_SQUARES_H
#define CHAPTER6____Q279_PERFECT_SQUARES_H

#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 动态规划
        vector<long> v(n+1, INT_MAX);
        v[0] = 0;
        for(int i=0;i<=n; i++){
            for(int j=1;j*j<=i;j++){
                // v[i-j*j]+1 表示由于(i-j*j)<i, 因此，取j时候，其剩余值的最小数量可通过查表得到
                // v[i] 每次遍历不同的j时候进行比较，更新v[i]
                v[i] = min(v[i-j*j]+1, v[i]);
            }
        }
        return v[n];
    }
};
#endif //CHAPTER6____Q279_PERFECT_SQUARES_H
