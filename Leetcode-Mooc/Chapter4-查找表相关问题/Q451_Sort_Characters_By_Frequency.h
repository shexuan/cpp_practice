//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q451_SORT_CHARACTERS_BY_FREQUENCY_H
#define CHAPTER4__Q451_SORT_CHARACTERS_BY_FREQUENCY_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto &c:s){
            m[c]++;
        }

        vector<pair<char, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<char, int> &l, pair<char, int> &r){ return l.second>r.second;});

        string res="";
        for(auto &p:v){
            string ts(p.second, p.first);
            res+=ts;
        }
        return res;
    }
};

#endif //CHAPTER4__Q451_SORT_CHARACTERS_BY_FREQUENCY_H
