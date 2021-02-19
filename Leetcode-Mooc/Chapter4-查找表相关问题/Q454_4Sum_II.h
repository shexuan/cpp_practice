//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q454_4SUM_II_H
#define CHAPTER4__Q454_4SUM_II_H

#include <vector>
#include <unordered_map>
//#include <map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // C、D所有元素组合的和先放入一个字典中，然后A、B数组遍历。如此可以保证时间复杂度为O(n^2)
        unordered_map<int, int> cdSum;
        for(auto &c:C){
            for(auto &d:D){
                cdSum[c+d]++;
            }
        }
        int ret=0;
        int res;
        for(auto &a:A){
            for(auto &b:B){
                res = -(a+b);
                if(cdSum.find(res)!=cdSum.end()){
                    ret+=cdSum[res];
                }
            }
        }

        return ret;
    }
};

#endif //CHAPTER4__Q454_4SUM_II_H
