//
// Created by shexuan on 2021/2/19.
//

#ifndef CHAPTER4__Q202_HAPPY_NUMBER_H
#define CHAPTER4__Q202_HAPPY_NUMBER_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycles;

        while (n!=1){
            if(cycles.find(n)!=cycles.end()){
                return false;
            }
            cycles.insert(n);
            n = _sqr_sum(n);
        }

        return true;
    }

    int _sqr_sum(int n){
        int res=0, tmp;  // 这里res要赋值，不然在重复调用的时候，会在上次调用的结果res继续加出错
        while (n>=10){
            tmp = (n%10);
            res += tmp*tmp;
            n = n/10;
        }
        res += n*n;
        return res;
    }
};
#endif //CHAPTER4__Q202_HAPPY_NUMBER_H
