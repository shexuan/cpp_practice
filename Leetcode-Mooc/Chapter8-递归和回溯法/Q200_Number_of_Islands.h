//
// Created by shexuan on 2021/3/2.
//

#ifndef CHAPTER8__Q200_NUMBER_OF_ISLANDS_H
#define CHAPTER8__Q200_NUMBER_OF_ISLANDS_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 四个移动方向, {row, col}
    vector<vector<int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int n=0, ncol, nrow;
    vector<vector<bool>>  visited;

    int numIslands(vector<vector<char>>& grid) {
        nrow = grid.size();
        ncol = grid[0].size();
        for(int i=0; i<nrow; i++){
            visited.push_back(vector<bool>(ncol, false));
        }

        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                // 每一个位置都进行尝试深度遍历，若没有访问过且为1的话说明是新岛屿
                if(!visited[r][c] && grid[r][c]=='1'){
                    traverseIsland(r, c, grid);
                    n++;
                }
            }
        }

        return n;
    }

    void traverseIsland(int ridx, int cidx, const vector<vector<char>>& grid){
        // 当前点为'0'说明已经到了岛屿边界，无法延伸
        if(grid[ridx][cidx]=='0') return;

        visited[ridx][cidx] = true;

        for(int i=0;i<4;i++){
            int cur_r = ridx + d[i][0];
            int cur_c = cidx + d[i][1];
            // 保证属于可访问位置且没有访问过
            if(cur_c>=0 && cur_c<ncol && cur_r>=0 && cur_r<nrow && !visited[cur_r][cur_c]){
                traverseIsland(cur_r, cur_c, grid);
            }
        }
    }
};




#endif //CHAPTER8__Q200_NUMBER_OF_ISLANDS_H
