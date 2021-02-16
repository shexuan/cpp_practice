//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q11_CONTAINER_WITH_MOST_WATER_H
#define __Q11_CONTAINER_WITH_MOST_WATER_H
#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 双指针变体——对撞指针
class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n<2){
            return 0;
        }
        int left = 0;
        int right = n-1;
        int area = 0, cur_area = 0;
        while (left<right){  // 选择小的一边进行移动，知道碰到一个比当前大的柱子停下
            cur_area = (right-left)*min(height[left], height[right]);
            area = max(area, cur_area);

            if(height[left]<=height[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;

    }
};
#endif //__Q11_CONTAINER_WITH_MOST_WATER_H
