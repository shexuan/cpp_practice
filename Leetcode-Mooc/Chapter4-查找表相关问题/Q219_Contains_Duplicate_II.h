//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER4__Q219_CONTAINS_DUPLICATE_II_H
#define CHAPTER4__Q219_CONTAINS_DUPLICATE_II_H

#include <unordered_map>
#include <vector>
using namespace std;


// 呆瓜解法
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        if (nums.empty() || k==0){
            return false;
        }
        int tmp, j=1;
        for(int i=0;i<nums.size()-1;i++){
            tmp = nums[i];
            while(j<i+k+1 && j<nums.size()){
                if(tmp==nums[j]){
                    return true;
                }
                mp[nums[j]]++;
                j++;
            }
            if(mp[nums[i+1]]>=2){ // 下一个元素在当前子串中出现了两次，肯定满足，可直接返回
                return true;
            }else{
                mp.erase(nums[i+1]);
            }
        }
        return false;
    }
};
#endif //CHAPTER4__Q219_CONTAINS_DUPLICATE_II_H
