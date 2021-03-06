//
// Created by shexuan on 2021/3/6.
//

#ifndef CHAPTER9__Q322_COIN_CHANGE_H
#define CHAPTER9__Q322_COIN_CHANGE_H

#include <vector>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 注意：因为要比较的是最小值，这个不可能的值就得赋值成为一个最大值
        vector<int> memo(amount+1, amount+2);

        // 理解 dp[0] = 0 的合理性，单独一枚硬币如果能够凑出面值，符合最优子结构
        memo[0] = 0;

        for(int i=1;i<=amount;i++){
            for(auto &coin:coins){
                // i-coin>=0   确保硬币可以填进去
                // memo[i-coin]!=amount+2  确保前一个是被填满了的而不是默认值
                if(i-coin>=0 && memo[i-coin]!=amount+2){
                    memo[i] = min(memo[i], 1+memo[i-coin]);
                }
            }
        }

        if(memo[amount]==amount+2) memo[amount] = -1;

        return memo[amount];
    }
};

#endif //CHAPTER9__Q322_COIN_CHANGE_H
