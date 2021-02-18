//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q75_SORT_COLORS_H
#define __Q75_SORT_COLORS_H
#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// 三路快速排序思路应用
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int size = nums.size();
        if (size < 2) {
            return;
        }

        // all in [0, zero) = 0
        // all in [zero, i) = 1
        // all in [two, len - 1] = 2

        // 循环终止条件是 i == two，那么循环可以继续的条件是 i < two
        // 为了保证初始化的时候 [0, zero) 为空，设置 zero = 0，
        // 所以下面遍历到 0 的时候，先交换，再加

        int zero = 0;
        // 为了保证初始化的时候 [two, len - 1] 为空，设置 two = len
        // 所以下面遍历到 2 的时候，先减，再交换

        int two = size;
        int i = 0;
        // 在这里pivot v是1
        // 当 i == two 上面的三个子区间正好覆盖了全部数组
        // 因此，循环可以继续的条件是 i < two
        while (i < two) {
            if(nums[i]==0){ // 等同于v<1
                swap(nums[i], nums[zero]);
                i++;
            }else if(nums[i]==1){
                i++;
            }else{
                two--;
                swap(nums[i], nums[two]);
            }
        }
    }
};

//        作者：liweiwei1419
//        链接：https://leetcode-cn.com/problems/sort-colors/solution/kuai-su-pai-xu-partition-guo-cheng-she-ji-xun-huan/
//        来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution75_2 {
public:
    void sortColors(vector<int>& nums) {
        // #inlude <map>
        // 先写个暴力解法——统计0，1，2的数量，然后给nums按顺序填数即可
        map<int, int> cunt;
        // 初始化一下cunt字典
        cunt.insert(pair<int, int>(0,0));
        cunt.insert(pair<int, int>(1,0));
        cunt.insert(pair<int, int>(2,0));

        int n = nums.size();
        for(int i=0; i<n; i++){
            switch(nums[i]){
                case 0:
                    cunt[0]++;
                    break;
                case 1:
                    cunt[1]++;
                    break;
                case 2:
                    cunt[2]++;
                    break;
                default:
                    cout << "Error Input!" << endl;
                    break;
            }
        }

        int index=0;
        for(int j=0;j<cunt[0];j++){
            nums[index++] = 0;

        }
        for(int j=0;j<cunt[1];j++){
            nums[index++] = 1;
        }
        for(int j=0;j<cunt[2];j++){
            nums[index++] = 2;
        }
    }
};
#endif //__Q75_SORT_COLORS_H
