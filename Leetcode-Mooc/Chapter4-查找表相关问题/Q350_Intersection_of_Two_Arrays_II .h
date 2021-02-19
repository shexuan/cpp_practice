//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER4__Q350_INTERSECTION_OF_TWO_ARRAYS_II_H
#define CHAPTER4__Q350_INTERSECTION_OF_TWO_ARRAYS_II_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        vector<int> ret;

        for(auto &i:nums1){
            m1[i]++;
        }

        for(auto &i:nums2){
            if(m1.find(i)!=m1.end() && m1[i]>0){
                ret.push_back(i);
                m1[i]--;
            }
        }
        return ret;
    }
};
#endif //CHAPTER4__Q350_INTERSECTION_OF_TWO_ARRAYS_II_H
