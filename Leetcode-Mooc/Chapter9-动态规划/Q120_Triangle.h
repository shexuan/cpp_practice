//
// Created by shexuan on 2021/3/4.
//

#ifndef CHAPTER9__Q120_TRIANGLE_H
#define CHAPTER9__Q120_TRIANGLE_H

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size_ = triangle.size();
        vector<int> memo;

        // base case
        if(size_==0) return 0;
        if(size_==1) return triangle[0][0];
        memo.push_back(triangle[0][0]); // triangle只有一个元素时

        for(int i=2; i<=size_; i++){ // i表示第2层，但是triangle索引时，其索引需要减1
            vector<int> tmp;
            for(int j=0; j<i; j++){
                // 状态转移公式
                int pre_left = j-1>=0 && j-1<memo.size() ? memo[j-1]:memo[j];
                int pre_right = j>=0 && j<memo.size() ? memo[j]:memo[j-1];
                tmp.push_back(min(pre_left+triangle[i-1][j], pre_right+triangle[i-1][j]));
            }
            memo = tmp;
        }

        int ret = INT_MAX;
        for(auto &i:memo){
            ret = min(ret, i);
        }

        return ret;
    }
};
#endif //CHAPTER9__Q120_TRIANGLE_H
