//
// Created by shexuan on 2021/2/28.
//

#ifndef CHAPTER8__Q17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define CHAPTER8__Q17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

 class Solution {
 public:
     string strings[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     vector<string> letterCombinations(string digits) {
         // string strings[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
         // BFS
         queue<string> q;
         vector<string> ret;
         q.push("");
         if(digits=="") return ret;
         char c;
         int size_ = digits.size(), i=0;
         while(i<size_){ // 每一次添加一个数字进行组合
             string tmp = strings[digits[i]-'2'];
             int tmp_size = tmp.size();
             int q_size = q.size();
             // queue中保存了之前数字的所有组合
             for(int i=0;i<q_size;i++){
                 string pre_str = q.front();
                 q.pop();
                 // tmp表示当前数字的字符串
                 for(int j=0;j<tmp_size; j++){
                     q.push(pre_str+tmp[j]);
                 }
             }
             i++;
         }

         int q_size = q.size();
         for(int i=0;i<q_size; i++){
             ret.push_back(q.front());
             q.pop();
         }

         return ret;
     }
 };

class Solution2 {
public:
    string strings[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        // DFS
        vector<string> ret;
        if(digits=="") return ret;
        dfs(0, "", digits, ret);
        return ret;
    }

    void dfs(int index, string comb, string digits, vector<string> &v){
        if(index==digits.size()){
            v.push_back(comb);
            return;
        }

        string tmp = strings[digits[index]-'2'];
        for(int i=0;i<tmp.size();i++){
            dfs(index+1, comb+tmp[i], digits, v);
        }
    }

};
#endif //CHAPTER8__Q17_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
