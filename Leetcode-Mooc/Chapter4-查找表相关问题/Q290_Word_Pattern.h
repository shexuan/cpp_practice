//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q290_WORD_PATTERN_H
#define CHAPTER4__Q290_WORD_PATTERN_H

#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;



class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> kv;  // 用来存放 pattern->s 映射关系
        unordered_map<string, char> vk; // 用来存放 s->pattern 映射关系，防止出现多key对一value的关系
        istringstream istr(s);
        string subs;
        for(auto &p:pattern){
            if(istr>>subs){
                // (1) 多个key对应同一个value，不符合直接返回
                // (2) 已有匹配模式, 判断匹配模式是否相等，不相等可直接返回
                if((kv.find(p)!=kv.end() && kv[p]!=subs) || (vk.find(subs)!=vk.end() && vk[subs]!=p) ){
                    return false;
                }
                if(kv.find(p)==kv.end()){  // 无匹配模式则直接建立匹配模式
                    kv[p] = subs;
                    vk[subs] = p;
                }
            }else{  // 匹配字符s中已经空了，说明两者长度不一致
                return false;
            }
        }
        if(istr>>subs){  // 模型字符pattern完了，匹配字符s还没完
            return false;
        }
        return true;
    }
};
#endif //CHAPTER4__Q290_WORD_PATTERN_H
