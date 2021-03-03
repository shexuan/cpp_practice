//
// Created by shexuan on 2021/3/1.
//

#ifndef CHAPTER8__Q93_RESTORE_IP_ADDRESSES_H
#define CHAPTER8__Q93_RESTORE_IP_ADDRESSES_H

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size()>12 || s.size()<4) return ret;

        dfs(0, 0, "", s, ret);
        return ret;
    }


    void dfs(int ip_idx, int str_idx, string ip, const string s, vector<string> &v){
        if(ip_idx==4){ // 四个段都已经处理完
            ip.pop_back();
            v.push_back(ip);
            return;
        }

        for(int i=str_idx; i<str_idx+3; i++){
            // 取完本ip字段，剩余字段的数字数量
            int rest_size = s.size()-i-1;
            // 剩余数字数量<=ip字段数*3 && 剩余数字数量>=ip字段数*1
            if(rest_size <= (3-ip_idx)*3 && rest_size>=(3-ip_idx)){
                string cur_ip = s.substr(str_idx, i-str_idx+1);
                // 首字为0的话则不能大于一个数字
                if(cur_ip[0]=='0' && cur_ip.size()>1) break;
                if(stoi(cur_ip)<=255){
                    dfs(ip_idx+1, i+1, ip+cur_ip+".", s, v);
                }
            }
        }

    }
};
#endif //CHAPTER8__Q93_RESTORE_IP_ADDRESSES_H
