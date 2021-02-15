//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
#define __Q80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
#pragma once
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 双指针问题
class Solution80 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }

        int slow=0, fast=1, cnt=0;
        for (;fast<n;fast++){
            if(nums[slow]!=nums[fast]){ // 快慢指针不相等时候，可以直接更新慢指针
                nums[++slow] = nums[fast];
                cnt = 0;
            }else{ // 快慢指针相等时候需要进行计数, cnt<1时候可以更新
                if(cnt<1){
                    nums[++slow] = nums[fast];  // 注意这里是先移动指针后赋值，所有最后return slow+1
                    cnt++;
                }
            }
        }
        return slow+1;
    }
};
#endif //__Q80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
