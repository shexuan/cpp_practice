//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q242_VALID_ANAGRAM_H
#define CHAPTER4__Q242_VALID_ANAGRAM_H

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
using  namespace std;

// 使用哈希表来计数
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms;
        for(auto &c:s){
            ms[c]++;
        }

        // 仅使用一个map
        // for(auto &c:t){
        //     if(ms.find(c)==ms.end()){
        //         return false;
        //     }else{
        //         ms[c]--;
        //         if(ms[c]==0){
        //             ms.erase(c);
        //         }
        //     }
        // }

        // 使用两个map
        unordered_map<char, int> mt;
        for(auto &c:t){
            mt[c]++;
        }

        return mt==ms;

        //return ms.empty();
    }
};


// 使用数组来计数
class Solution_2 {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};

        for(auto &c:s){
            arr[int(c-'a')]++;
        }

        for(auto &c:t){
            arr[int(c-'a')]--;
        }

        for(int i=0; i<26; i++){
            if(arr[i]!=0){
                return false;
            }
        }

        return true;
    }
};


//
#endif //CHAPTER4__Q242_VALID_ANAGRAM_H
