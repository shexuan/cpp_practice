//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER4__Q349_INTERSECTION_OF_TWO_ARRAYS_H
#define CHAPTER4__Q349_INTERSECTION_OF_TWO_ARRAYS_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> ret;
        for(auto &i:nums1){
            s1.insert(i);
        }

        for(auto &i:nums2){
            if(s1.find(i)!=s1.end()){
                ret.insert(i);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};
#endif //CHAPTER4__Q349_INTERSECTION_OF_TWO_ARRAYS_H
