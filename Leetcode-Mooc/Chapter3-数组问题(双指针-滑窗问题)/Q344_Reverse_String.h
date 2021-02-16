//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q344_REVERSE_STRING_H
#define __Q344_REVERSE_STRING_H
#pragma once
#include <vector>
#include <string>

using namespace std;

// 双指针变体——对撞指针
class Solution344 {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if(n<2){
            return;
        }

        int left=0, right=n-1;
        while(left<right){
            swap(s[left++], s[right--]);
        }
    }
};



#endif //__Q344_REVERSE_STRING_H
