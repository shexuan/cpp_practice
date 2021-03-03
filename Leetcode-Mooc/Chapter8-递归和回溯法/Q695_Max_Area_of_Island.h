//
// Created by shexuan on 2021/3/3.
//

#ifndef CHAPTER8__Q695_MAX_AREA_OF_ISLAND_H
#define CHAPTER8__Q695_MAX_AREA_OF_ISLAND_H

#include <vector>

using namespace std;


class Solution {
public:
    int nrow, ncol, num;
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        nrow = grid.size(), ncol = grid[0].size();
        visited = vector<vector<bool>>(nrow, vector<bool>(ncol, false));
        int ret = INT_MIN;
        for(int r=0; r<nrow; r++){
            for(int c=0; c<ncol; c++){
                num = 0;
                if(!visited[r][c] && grid[r][c]==1){
                    dfs(r, c, grid);
                }
                ret = max(ret, num);
            }
        }
        return ret;
    }

    void dfs(int ridx, int cidx, const vector<vector<int>>& grid){
        if(!inArea(ridx, cidx) || grid[ridx][cidx]==0 || visited[ridx][cidx])
            return;

        num++;
        visited[ridx][cidx] = true;
        for(int i=0;i<4;i++){
            int new_r = ridx + d[i][0];
            int new_c = cidx + d[i][1];
            dfs(new_r, new_c, grid);
        }

    }

    bool inArea(int ridx, int cidx){
        return ridx<nrow && ridx>=0 && cidx<ncol && cidx>=0;
    }
};
#endif //CHAPTER8__Q695_MAX_AREA_OF_ISLAND_H
