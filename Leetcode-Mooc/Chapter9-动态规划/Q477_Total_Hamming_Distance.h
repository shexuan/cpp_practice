//
// Created by shexuan on 2021/3/6.
//

#ifndef CHAPTER9__Q477_TOTAL_HAMMING_DISTANCE_H
#define CHAPTER9__Q477_TOTAL_HAMMING_DISTANCE_H

#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            int ones = 0;
            for (auto num : nums) {
                if (num >> i & 1)
                    ones ++;
            }
            res += ones * (nums.size() - ones);
        }
        return res;
    }
};


// https://leetcode-cn.com/problems/total-hamming-distance/solution/python3-wei-yun-suan-zhi-yi-ming-ju-chi-zong-he-by/

#endif //CHAPTER9__Q477_TOTAL_HAMMING_DISTANCE_H
