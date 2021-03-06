//
// Created by shexuan on 2021/3/7.
//

#ifndef CHAPTER10__Q435_NON_OVERLAPPING_INTERVALS_H
#define CHAPTER10__Q435_NON_OVERLAPPING_INTERVALS_H

#include <vector>

using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];   // 按照end来排序，从小到大
        return a[0]<b[0];  // end相同，按start从小到大排序
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0][1]; // 记录区间分割点
        int count = 1;
        for(int i=1;i<intervals.size();i++){
            if(end<=intervals[i][0]){ // 没有重叠，可以保存
                end = intervals[i][1]; // 更新end
                count++; // 更新未重叠的个数
            }
        }

        return intervals.size()-count;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/non-overlapping-intervals/solution/435-wu-zhong-die-qu-jian-tan-xin-jing-di-qze0/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#endif //CHAPTER10__Q435_NON_OVERLAPPING_INTERVALS_H
