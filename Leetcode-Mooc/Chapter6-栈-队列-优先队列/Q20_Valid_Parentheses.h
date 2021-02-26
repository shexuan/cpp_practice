//
// Created by shexuan on 2021/2/23.
//

#ifndef CHAPTER6____Q20_VALID_PARENTHESES_H
#define CHAPTER6____Q20_VALID_PARENTHESES_H

#include <stack>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp;
        mp.insert(pair<char, char>(')', '('));
        mp.insert(pair<char, char>(']', '['));
        mp.insert(pair<char, char>('}', '{'));
        for(int i=0; i<s.size(); i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(stk.size()==0 || mp[s[i]]!=stk.top()){  // 栈为空或者没匹配上，返回false
                    return false;
                }else{
                    stk.pop();  // 匹配上了则弹出栈顶元素
                }
            }else{
                stk.push(s[i]);
            }
        }

        return stk.empty();
    }
};
#endif //CHAPTER6____Q20_VALID_PARENTHESES_H
