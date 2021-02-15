//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q27_REMOVE_ELEMENT_H
#define __Q27_REMOVE_ELEMENT_H

#pragma once

#include <vector>
#include <string>

using namespace std;

// 双指针问题
class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int slow=0, fast=0;
        for(; fast<n;fast++){
            if(nums[fast]!=val){  // 快指针不指向目标值时，才更新慢指针
                nums[slow++] = nums[fast];  // 注意这里是先更赋值再移动指针
            }
        }
        return slow;
    }
};
#endif //__Q27_REMOVE_ELEMENT_H
