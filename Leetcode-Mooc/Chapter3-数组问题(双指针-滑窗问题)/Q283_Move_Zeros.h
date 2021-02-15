//
// Created by shexuan on 2021/2/15.
//

#ifndef __Q283_MOVE_ZEROS_H
#define __Q283_MOVE_ZEROS_H
#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 双指针算法
 class Solution283 {
 public:
     void moveZeroes(vector<int>& nums) {
         int n = nums.size();
         if(n<=1){
             return;
         }
         for(int slow=0, fast=0; fast<n;fast++){
             if(nums[fast]!=0){  // fast指针碰到0时候就不需要考虑与slow交换以及更新slow指针的问题了
                 if(nums[slow]==0){
                     swap(nums[slow], nums[fast]);
                 }
                 slow++; //当前slow已经不为0，因此需要+1移动以找到
             }
         }
     }
 };


// 另一种解法，先将所有非0都填上，然后补上后续的0，这种更慢一些
class Solution283_2 {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return;
        }
        int idx = 0;
        // 先将非0部分填上
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[idx++]=nums[i];
            }
        }
        // padding 0
        for(;idx<n;idx++){
            nums[idx]=0;
        }
    }
};

#endif //__Q283_MOVE_ZEROS_H
