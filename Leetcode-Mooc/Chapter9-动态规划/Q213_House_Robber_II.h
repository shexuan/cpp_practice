//
// Created by shexuan on 2021/3/5.
//

#ifndef CHAPTER9__Q213_HOUSE_ROBBER_II_H
#define CHAPTER9__Q213_HOUSE_ROBBER_II_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 特例，个数小于3
        int ret=0;
        if(nums.size()<3){
            for(auto &i:nums){
                if(i>ret) ret = i;
            }

            return ret;
        }

        // 有两种选择：不选第一个或者不选最后一个，然后从中选出一个最大的就行
        return max(robHelper(vector<int>(nums.begin()+1, nums.end())),
                   robHelper(vector<int>(nums.begin(), nums.end()-1)));

    }

    int robHelper(vector<int> nums){
        vector<int> memo(nums.size(), 0);

        // base case
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);

        for(int i=2;i<nums.size();i++){
            // 状态转移公式： f(k) = max(f(k-2)+f(k), f(k-1))
            memo[i] = max(memo[i-2]+nums[i], memo[i-1]);
        }

        return memo[nums.size()-1];
    }
};

#endif //CHAPTER9__Q213_HOUSE_ROBBER_II_H
