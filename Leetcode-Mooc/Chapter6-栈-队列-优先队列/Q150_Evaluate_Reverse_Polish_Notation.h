//
// Created by shexuan on 2021/2/24.
//

#ifndef CHAPTER6____Q150_EVALUATE_REVERSE_POLISH_NOTATION_H
#define CHAPTER6____Q150_EVALUATE_REVERSE_POLISH_NOTATION_H

#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;



class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> data;
        unordered_map<string, int> ops;
        ops["+"]=0;
        ops["-"]=1;
        ops["*"]=2;
        ops["/"]=3;
        int len = tokens.size(), i=0;

        while(i<len){
            // 数字先入栈，碰到操作符再出栈
            if(ops.find(tokens[i])==ops.end()){
                data.push(stoi(tokens[i++]));
            }else{ // 碰到运算符就从栈中取出栈顶两位数字进行计算
                int right = data.top();
                data.pop();
                int left = data.top();
                data.pop();
                right = calc(left, right, ops[tokens[i]]); // (left ops right)
                data.push(right);
                i++;
            }
        }
        return data.top();
    }

    int calc(int a, int b, int op){
        int ret;
        switch(op){  // c++中，是不能用字符串来作为case的标签的
            case 0: // +
                ret = a+b;
                break;
            case 1: // -
                ret = a-b;
                break;
            case 2: // *:
                ret = a*b;
                break;
            case 3: // /:
                ret = a/b;
                break;
            default:
                cout << "In valid operator!" << endl;
                break;
        }
        return ret;
    }
};
#endif //CHAPTER6____Q150_EVALUATE_REVERSE_POLISH_NOTATION_H
