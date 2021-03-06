//
// Created by shexuan on 2021/3/3.
//

#ifndef CHAPTER9__Q198_HOUSE_ROBBER_H
#define CHAPTER9__Q198_HOUSE_ROBBER_H

#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size_ = nums.size();
        if(size_==0) return 0;
        if(size_==1) return nums[0];
        vector<int> memo(size_+1, -1);

        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        // memo[2] = max(memo[1], memo[0]+nums[2])
        // 状态转移公式：f(k) = max(f(k-1), f(k-2)+nums[k])

        for(int i=2; i<size_; i++){
            memo[i] = max(memo[i-1], memo[i-2]+nums[i]);
        }

        return memo[size_-1];
    }
};

#endif //CHAPTER9__Q198_HOUSE_ROBBER_H
