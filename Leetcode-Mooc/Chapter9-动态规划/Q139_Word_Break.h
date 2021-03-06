//
// Created by shexuan on 2021/3/6.
//

#ifndef CHAPTER9__Q139_WORD_BREAK_H
#define CHAPTER9__Q139_WORD_BREAK_H

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(string &word:wordDict) wordSet.insert(word);

        int len = s.size();
        vector<bool> memo(len+1, false);
        memo[0] = true;

        for(int i=1; i<=len; i++){
            for(int j=i-1; j>=0; j--){
                string suffix = s.substr(j, i-j); // 后缀部分
                // 后缀部分是单词，且左侧子串[0,j-1]的dp[j]为真
                if(wordSet.find(suffix)!=wordSet.end() && memo[j]){
                    memo[i] = true;
                    break; // memo[i] = true了，i长度的子串已经可以拆成单词了，不需要j继续划分子串了
                }
            }
        }

        return memo[len];
    }
};



// 作者：xiao_ben_zhu
// 链接：https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#endif //CHAPTER9__Q139_WORD_BREAK_H
