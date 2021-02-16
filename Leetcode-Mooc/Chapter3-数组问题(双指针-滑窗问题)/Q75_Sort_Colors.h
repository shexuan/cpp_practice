//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q75_SORT_COLORS_H
#define __Q75_SORT_COLORS_H
#pragma once

#include <map>
#include <vector>
#include <string>
using namespace std;

// 快速排序思路应用
class Solution75 {
public:
    void sortColors(vector<int>& nums) {
        // #inlude <map>
        // 先写个暴力解法——统计0，1，2的数量，然后给nums按顺序填数即可
        map<int, int> cunt;
        // 初始化一下cunt字典
        cunt.insert(pair<int, int>(0,0));
        cunt.insert(pair<int, int>(1,0));
        cunt.insert(pair<int, int>(2,0));

        int n = nums.size();
        for(int i=0; i<n; i++){
            switch(nums[i]){
                case 0:
                    cunt[0]++;
                    break;
                case 1:
                    cunt[1]++;
                    break;
                case 2:
                    cunt[2]++;
                    break;
                default:
                    cout << "Error Input!" << endl;
                    break;
            }
        }

        int index=0;
        for(int j=0;j<cunt[0];j++){
            nums[index++] = 0;

        }
        for(int j=0;j<cunt[1];j++){
            nums[index++] = 1;
        }
        for(int j=0;j<cunt[2];j++){
            nums[index++] = 2;
        }
    }
};
#endif //__Q75_SORT_COLORS_H
