//
// Created by shexuan on 2021/2/20.
//

#ifndef __Q15_3SUM_H
#define __Q15_3SUM_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        if(nums.size()<3 || nums[nums.size()-1]<0){  // 全负数，可以直接返回
            return ret;
        }
        for(int i=0; i<nums.size()-2; i++){
            int sum, tmp=nums[i];
            if(tmp>0){  // 当前遍历位置最小值都大于0，和肯定大于0
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1, right=nums.size()-1;

            while(left<right){
                sum = tmp+nums[left]+nums[right];
                if(sum==0){
                    vector<int> v;
                    v.push_back(tmp);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    ret.push_back(v);
                    while(left<right and nums[left]==nums[left+1]) // 去重
                        left++;
                    while(left<right and nums[right]==nums[right-1]) // 去重
                        right--;

                    left++;
                    right--;
                }else if(sum>0){
                    right--;
                }else{ // sum<0
                    if(nums[right]<=0){ // 最大值都小于0了，可以直接退出本轮循环了
                        break;
                    }
                    left++;
                }
            }
        }
        return ret;
    }
};
#endif //__Q15_3SUM_H
