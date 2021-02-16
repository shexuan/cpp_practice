//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q345_REVERSE_VOWELS_OF_A_STRING_H
#define __Q345_REVERSE_VOWELS_OF_A_STRING_H

#include <vector>
#include <string>
#include <set>;
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        // vowels 元音字母：aeiou
        int n = s.size();
        if(n<2){
            return s;
        }

        int left=0, right=n-1;
        while (left<right){
            while(left<right && !is_vowels(s[left])){
                left++;
            }
            while(left<right && !is_vowels(s[right])){
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }

    bool is_vowels(char c){
        // return vowels.find(c)!=vowels.end(); // 利用find函数
        return vowels.count(c); // 利用count函数, 两个函数速度差不多
    }

private:
    // 若这个属性放入is_vowel函数中会大大减慢速度，这儿可能是因为每次运行时都需要初始化一个set？
    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

};
#endif //__Q345_REVERSE_VOWELS_OF_A_STRING_H
