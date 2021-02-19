//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q217_CONTAINS_DUPLICATE_H
#define CHAPTER4__Q217_CONTAINS_DUPLICATE_H

#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> sets;
        for(auto &i:nums){
            if(sets.find(i)!=sets.end()){
                return true;
            }else{
                sets.insert(i);
            }
        }
        return false;
    }
};
#endif //CHAPTER4__Q217_CONTAINS_DUPLICATE_H
