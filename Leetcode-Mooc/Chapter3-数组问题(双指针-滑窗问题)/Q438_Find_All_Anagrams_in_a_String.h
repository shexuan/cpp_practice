//
// Created by shexuan on 2021/2/17.
//

#ifndef __Q438_FIND_ALL_ANAGRAMS_IN_A_STRING_H
#define __Q438_FIND_ALL_ANAGRAMS_IN_A_STRING_H
#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;


// 双指针 + 滑窗
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<int> ret;
        if(np>ns){
            return ret;
        }

        map<char, int> pm; // target map
        map<char, int> wm; // window map
        // 初始化target map
        for(auto &c:p){
            pm[c]+=1;
        }

        int left=0, right=0;
        char c;
        while(right<ns){
            c = s[right];
            if(!pm.count(c)){  // 当前right位置字符不在目标子串中
                ++right;  // 更新左右指针至right+1
                left = right;
                wm.clear();  // 清空当前窗口子串
            }else{  // right位置字符在子串中
                wm[c]+=1;
                if(right-left+1==np){  // 子串长度与目标长度一致
                    if(wm==pm){  // 子串字符与目标字符一致
                        ret.push_back(left);
                    }
                    // 由于window与目标长度已经相等了，因此此时必须left右移
                    wm[s[left]]-=1;  // lwindow map中left对应字符的计数减1
                    left++;   // left右移一位
                }

                // 到这里window size肯定小于目标子串长度（若相等前面一步left++也使得长度不相等了）
                right++;
            }
        }
        return ret;

    }
};

#endif //__Q438_FIND_ALL_ANAGRAMS_IN_A_STRING_H
