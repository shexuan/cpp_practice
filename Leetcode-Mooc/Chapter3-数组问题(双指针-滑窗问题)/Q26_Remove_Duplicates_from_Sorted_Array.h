//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define __Q26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#pragma once
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 双指针算法
class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return 0;
        }
        int slow=0, fast=1;
        for(;fast<n;fast++){
            if(nums[slow]!=nums[fast]){ // 两者不等时就更新慢指针的值
                nums[++slow] = nums[fast];
            }
        }
        return slow+1;
    }
};
#endif //__Q26_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
