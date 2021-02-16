//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define __Q3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

// 双指针（快慢指针）+ 滑窗问题


// 大佬方案，利用数组储存，一次遍历即可
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[128];
        int n=s.size();
        if (n<2){
            return n;
        }
        for(int i=0;i<128;i++) {
            arr[i]=-1;
        }
        int start=0,res=0;
        for(int i=0;i<n;i++){
            int index = (int)s[i];  // 强转成int
            start = max(start, arr[index]+1); // arr[index]+1中的+1表示重复位置的下一位
            res = max(res, i-start+1); // i表示重复字符的当前位置，start表示重复字符的上一个位置
            arr[index] = i;
        }
        return res;
    }
};

// 作者：legendarygz
// 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/jing-jian-yi-dong-ban-by-legendarygz-9thp/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 利用字典来储存位置索引
 class Solution_2 {
 public:
     int lengthOfLongestSubstring(string s) {
         int n = s.size();
         if(n<2){
             return n;
         }
         map<char, int> subs;  // value表示字符索引
         subs.insert(pair<char, int>(s[0], 0));
         int slow=0, fast=1, ret=0;
         while(fast<n){
             //（count==0）或者（count!=0但subs中重复字符的位置索引小于slow，即不在当前子串中）才进行循环
             while(fast<n && (!subs.count(s[fast]) || subs[s[fast]]<slow)){
                 subs[s[fast]] = fast;
                 fast++;
             }
             // 上面fast已经走到了第一个重复值的位置或者末尾
             // 但是此时用来记录的容器subs中还没有更新重复字符的位置值，因为我们用的后置递加
             ret = max(ret, fast-slow);

             slow = subs[s[fast]]; // slow更新到重复字符位置
             slow++; // 更新到重复位置的下一个位置，以开始下一个寻找的循环

             subs[s[fast]] = fast;  // 将最后一个后置fast递加的重复字符位置进行更新
             fast++;
         }
         return ret;
     }
 };


// 使用集合，不存索引
 class Solution_3 {
 public:
     int lengthOfLongestSubstring(string s) {
         int n = s.size();
         if(n<2){
             return n;
         }
         unordered_set<char> subs;
         subs.insert(s[0]);
         int slow=0, fast=1, ret = 0;
         while (fast<n){
             // 先移动fast直到slow-fast之间存在重复字符
             // 此时便可以记录一下当前非重复子串长度 fast-slow（此时fast正好位于重复位置）
             while(fast<n && !subs.count(s[fast])){  // count=0 时没重复，fast继续走
                 subs.insert(s[fast++]);
             }
             ret = max(ret, fast-slow);

             // 此时上面的fast已经找到子串后面的重复位置，slow走到子串前面的重复位置
             while(slow<fast && s[slow]!=s[fast]){ // 这个循环slow最后到了重复字符的位置的才退出
                 subs.erase(s[slow++]);
             }
             slow++; // slow到达重复字符位置的下一个位置才行，继续寻找下一个非重复子串

             fast++; // slow到达重复字符位置的下一个位置, 即子串不存在重复，fast继续走一步
         }

         return ret;
     }
};

#endif