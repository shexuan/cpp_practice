//
// Created by shexuan on 2021/3/7.
//

#ifndef CHAPTER10__Q392_IS_SUBSEQUENCE_H
#define CHAPTER10__Q392_IS_SUBSEQUENCE_H

#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;

        int s_idx=0, t_idx=0;
        while(s_idx<s.size() && t_idx<t.size()){
            if(s[s_idx]==t[t_idx]){ // s和t的字符匹配上了
                s_idx++;
                t_idx++;
            }else{ // s和t的字符未能匹配上，t_idx后移继续寻找
                t_idx++;
            }
        }

        return s_idx==s.size();
    }
};



#endif //CHAPTER10__Q392_IS_SUBSEQUENCE_H
