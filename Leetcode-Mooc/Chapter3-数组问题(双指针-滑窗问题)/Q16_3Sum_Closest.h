//
// Created by shexuan on 2021/2/20.
//

#ifndef __Q16_3SUM_CLOSEST_H
#define __Q16_3SUM_CLOSEST_H

#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len=nums.size();
        int ret[2] = {0, INT_MAX}; // sum[0]=> 3sum; sum[1]=> diff

        for(int i=0; i<len-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int diff, left=i+1, right=len-1;

            while(left<right){
                diff = nums[i]+nums[left]+nums[right]-target;
                if(abs(diff)<abs(ret[1])){
                    ret[0] = nums[i]+nums[left]+nums[right];
                    ret[1] = diff;
                }
                if(diff==0){
                    return target;
                }else if(diff>0){
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    right--;
                }else{  // diff < 0
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    left++;
                }
            }
        }
        return ret[0];
    }
};
#endif //__Q16_3SUM_CLOSEST_H
