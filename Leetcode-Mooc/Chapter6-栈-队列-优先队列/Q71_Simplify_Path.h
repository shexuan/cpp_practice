//
// Created by shexuan on 2021/2/24.
//

#ifndef CHAPTER6____Q71_SIMPLIFY_PATH_H
#define CHAPTER6____Q71_SIMPLIFY_PATH_H

#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int len = path.size();
        char c;
        string s="";
        int i=0;
        while(i<len){  // 从根目录开始入栈，这样碰到".."可以弹出上层目录
            while(i<len && path[i]!='/'){  // 每次碰到 “/” 跳出内层循环，并将此轮s压入栈
                s+=path[i];
                i++;
            }
            if(s!=""){
                if(s==".."){  // 碰到".."可以弹出上层目录
                    if(!stk.empty()) stk.pop();
                }else if(s!="."){ // 遇上连续的 "/" s就是空了，因此入栈前先检查
                    stk.push(s);
                }
            }
            s=""; // 字符串清空
            i++;
        }

        // 出栈, 先出来的是底层目录，根目录最先进栈因此最后出来
        string new_path = "/";
        while(!stk.empty()){
            new_path = "/"+stk.top()+new_path;
            stk.pop();
        }
        // 即上面栈不为空的时候会多加一个"/"，需要去掉
        if(new_path.size()>1) new_path.erase(new_path.end()-1);
        return new_path;
    }
};
#endif //CHAPTER6____Q71_SIMPLIFY_PATH_H
