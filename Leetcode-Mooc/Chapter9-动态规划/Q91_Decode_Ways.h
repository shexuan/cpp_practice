//
// Created by shexuan on 2021/3/5.
//

#ifndef CHAPTER9__Q91_DECODE_WAYS_H
#define CHAPTER9__Q91_DECODE_WAYS_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int numDecodings(string s) {
        // 特例
        if(s.size()==0 || s[0]=='0') return 0;

        vector<int> memo(s.size(), 0);
        // base case
        memo[0] = 1; // index = 0的位置的走法

        for(int i=1; i<s.size();i++){
            int ans1, ans2;
            // 如果 s[i] == '0' ，字符 s[i] 就不能单独解码，所以当 s[i] != '0' 时，dp[i] = dp[i - 1] * 1
            if(s[i]!='0') memo[i] = memo[i-1];

            // 若s[i-1,i+1) 取值在10-26之间，说明可以一次走两步，所以还要加上前两步的所有走法
            if(stoi(s.substr(i-1, 2)) >= 10 && stoi(s.substr(i-1, 2)) <= 26){
                if(i==1){
                    memo[i]++;
                }else{
                    memo[i] += memo[i-2];
                }
            }

        }

        //for_each(memo.begin(), memo.end(), [](int a){cout << a << " ";});
        return memo.back();
    }
};


#endif //CHAPTER9__Q91_DECODE_WAYS_H
