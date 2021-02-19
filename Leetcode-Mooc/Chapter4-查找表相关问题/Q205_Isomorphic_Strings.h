//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q205_ISOMORPHIC_STRINGS_H
#define CHAPTER4__Q205_ISOMORPHIC_STRINGS_H

#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int ns = s.length();
        int nt = t.length();
        if(ns!=nt){
            return false;
        }

        int i=0;
        char char_s, char_t;
        while(i<ns){
            char_s = s[i];
            char_t = t[i];
            // 判断映射关系是否正确, 键值对应不上:（1）1键多值；（2）1值多键
            if((s2t.find(char_s)!=s2t.end() && s2t[char_s]!=char_t) || \
                (t2s.find(char_t)!=t2s.end() && t2s[char_t]!=char_s)){
                return false;
            }

            // 无匹配关系时候添加映射关系
            if(s2t.find(char_s)==s2t.end()){
                s2t[char_s] = char_t;
                t2s[char_t] = char_s;
            }
            i++;
        }
        return true;
    }
};
#endif //CHAPTER4__Q205_ISOMORPHIC_STRINGS_H
