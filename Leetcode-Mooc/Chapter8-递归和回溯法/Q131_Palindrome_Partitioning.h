//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q131_PALINDROME_PARTITIONING_H
#define CHAPTER8__Q131_PALINDROME_PARTITIONING_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size()==0) return ret;

        vector<string> vStr;
        dfs(0, s, vStr, ret);
        return ret;
    }

    void dfs(int start, const string &s, vector<string> &vStr, vector<vector<string>> &res){
        // npos 表示从start开始截取几个字符串，如n=1则表示仅取start位置的字符串
        if(start==s.size()){
            res.push_back(vStr);
            return;
        }
        // 循环i表示取几位字符作为子串
        for(int i=1; i<s.size()-start+1; i++){
            string cur = s.substr(start, i);
            if(!isPalindrome(cur)) continue;
            vStr.push_back(cur);
            dfs(start+i, s, vStr, res);
            // 回溯，尝试别的划分方式
            vStr.pop_back();
        }

    }


    bool isPalindrome(const string &str){
        int size_ = str.size();
        int left=0, right=size_-1;

        while(left<right){
            if(str[left]!=str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
#endif //CHAPTER8__Q131_PALINDROME_PARTITIONING_H
