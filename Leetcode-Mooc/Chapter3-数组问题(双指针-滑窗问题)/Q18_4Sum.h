//
// Created by shexuan on 2021/2/20.
//

#ifndef __Q18_4SUM_H
#define __Q18_4SUM_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        if(len<4 || nums[len-1]<0 || nums[0]>0){  // 特例判断
            return ret;
        }
        for(int i=0; i<len-3; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<len-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int ps = nums[i]+nums[j]; // part sum of nums[i] + nums[j]
                int left = j+1, right=len-1, res;
                while(left<right){
                    res = ps+nums[left]+nums[right]-target;
                    if(res==0){
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left<right && nums[left]==nums[left+1])
                            left++;
                        while (left<right && nums[right]==nums[right-1])
                            right--;

                        left++;
                        right--;
                    }else if(res>0){
                        right--;
                    }else{  // res < 0
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};

#endif //__Q18_4SUM_H
