//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H
#define __Q167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H

#pragma once
#include <vector>
#include <string>

using namespace std;

// 双指针——对撞指针
class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ret;
        int left=0, right=n-1, sum;
        while (left<right){
            sum = numbers[left]+numbers[right];
            if(sum==target){
                ret.push_back(++left);
                ret.push_back(++right);
                return ret;
            }
            if(sum>target){  // 和大了，减小大的那边数字
                right--;
            }else{
                left++;
            }
        }
        ret.push_back(0);  // 没找到答案，返回两个0
        ret.push_back(0);
        return ret;
    }
};
#endif //__Q167_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H
