//
// Created by shexuan on 2021/3/7.
//

#ifndef CHAPTER10__Q455_ASSIGN_COOKIES_H
#define CHAPTER10__Q455_ASSIGN_COOKIES_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;

        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int s_idx=0, g_idx=0, ret=0;


        // 把大饼干尽量分给大孩子
        while(s_idx<s.size() && g_idx<g.size()){
            if(s[s_idx]>=g[g_idx]){ // 饼干大于孩子要的，可以分配
                s_idx++;
                g_idx++;
                ret++;
            }else{ // 饼干小于孩子要的，这个孩子吃不到饼干了，看看下一个孩子能吃到不
                g_idx++;
            }
        }

        return ret;
    }
};
#endif //CHAPTER10__Q455_ASSIGN_COOKIES_H
