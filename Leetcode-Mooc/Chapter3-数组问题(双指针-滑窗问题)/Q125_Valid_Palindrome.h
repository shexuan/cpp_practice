//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q125_VALID_PALINDROME_H
#define __Q125_VALID_PALINDROME_H

#include <string>
#include <vector>

using namespace std;


// 双指针变体——对撞指针
class Solution125 {
public:
    bool isPalindrome(string s) {
        // ascii num: 0-9 => 48-57;
        // ascii lower alphabet: a-z => 97-122
        // ascii upper alphabet: A-Z => 65-90
        int n = s.size();
        if(n<2){
            return true;
        }

        int left=0, right=n-1;
        while (left<right){
            while(left<right && transform(s[left])==-1){  // 跳过标点空格等字符
                left++;
            }

            while(left<right && transform(s[right])==-1){  // 跳过标点空格等字符
                right--;
            }

            // 有一种情况是全是标点等字符，这样left，right的transform返回值都是-1，此时也是符合的
            if(transform(s[left])!=transform(s[right])){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;

    }

    int transform(char a){
        // 全部转成数字，大写转小写，小写不变, 数字不变
        if (a>=48 && a<=57){
            return a;
        }

        if(a>=97 && a<=122){
            return a;
        }

        if(a>=65 && a<=90){
            return a+32;
        }

        return -1;
    }
};

#endif //__Q125_VALID_PALINDROME_H
