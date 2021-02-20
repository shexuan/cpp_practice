//
// Created by shexuan on 2021/2/20.
//

#ifndef CHAPTER4__Q447_NUMBER_OF_BOOMERANGS_H
#define CHAPTER4__Q447_NUMBER_OF_BOOMERANGS_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int nums = points.size();
        if(nums<3){
            return 0;
        }
        int ret=0;
        unordered_map<int, int> dist;  // key=> distance, value=> the same distance point count
        int d;
        for(auto &p:points){
            for(auto &q:points){
                d = (p[0]-q[0])*(p[0]-q[0])+ \
                    (p[1]-q[1])*(p[1]-q[1]);
                dist[d]++;
            }
            for(auto &d:dist){
                ret += d.second*(d.second-1);
            }
            dist.clear();
        }
        return ret;
    }
};
#endif //CHAPTER4__Q447_NUMBER_OF_BOOMERANGS_H
