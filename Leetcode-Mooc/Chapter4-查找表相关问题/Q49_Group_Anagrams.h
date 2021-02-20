//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER4__Q49_GROUP_ANAGRAMS_H
#define CHAPTER4__Q49_GROUP_ANAGRAMS_H

#include <vector>
#include <string>
#include <unordered_map>

using  namespace std;

// 呆瓜字符排序然后作为map key方法
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > dic;
        for(auto &s:strs){
            string new_s = s;
            sort(new_s.begin(), new_s.end());
            dic[new_s].push_back(s);
        }

        vector<vector<string> > ret;
        for(auto &d:dic){
            ret.push_back(d.second);
        }

        return ret;
    }
};


// 大佬自建hash函数法
class Solution_2 {
public:

    int hash(string s) {
        if (!s.size()) return 0;
        int ans = 0;
        for (char i: s) {
            ans = ans + 5*i*i*i/26 + i*1009 - i*i*997;  // 谁便写的，没有什么规律，尽量让哈希散列的范围较大就行了。避免不必要的碰撞。
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if (!strs.size()) return {};
        vector<vector<string>> ans;
        int index = 0;
        unordered_map<int, int> map;    //  第一个存哈希值， 第二个存 下标

        for (int i = 0; i < strs.size(); i ++ ) {
            int t = hash(strs[i]);
            if (map.find(t) != map.end()) {
                ans[map[t]].push_back(strs[i]);
            } else {
                map[t] = index;
                index ++ ;
                vector<string> temp;
                temp.push_back(strs[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

//作者：maserhe
//        链接：https://leetcode-cn.com/problems/group-anagrams/solution/shou-xie-ha-xi-beats100shi-jian-fu-za-du-fnb1/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#endif //CHAPTER4__Q49_GROUP_ANAGRAMS_H
