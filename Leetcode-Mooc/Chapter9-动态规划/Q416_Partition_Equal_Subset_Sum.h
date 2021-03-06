//
// Created by shexuan on 2021/3/5.
//

#ifndef CHAPTER9__Q416_PARTITION_EQUAL_SUBSET_SUM_H
#define CHAPTER9__Q416_PARTITION_EQUAL_SUBSET_SUM_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i:nums)
            sum+=i;

        if(sum%2!=0) return false;

        int target = sum/2;
        vector<vector<bool> > memo(nums.size(), vector<bool>(target+1, false));
        // 先填表格第 0 行，第 1 个数只能让容积为它自己的背包恰好装满
        if (nums[0] <= target) {
            memo[0][nums[0]] = true;
        }

        for(int i=1;i<nums.size();i++){ // 某个数的那一行
            for(int j=0;j<=target;j++){ // 当前格子空间
                // 先将上一层的填法copy下来
                memo[i][j] = memo[i-1][j];
                // 上一层的填法满足当前格子，则不用管了
                if(memo[i][j]) continue;

                // 当前格子的空间大于当前行的数值，看看[j-[nums[i]]]位置是否为填满(true)，为true的话则可以将那里的物品加进来
                if(nums[i]<j) memo[i][j] = memo[i-1][j-nums[i]];
            }
        }

        return memo[nums.size()-1][target];
    }
};

#endif //CHAPTER9__Q416_PARTITION_EQUAL_SUBSET_SUM_H
