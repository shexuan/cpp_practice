//
// Created by shexuan on 2021/3/3.
//

#ifndef CHAPTER8__Q463_ISLAND_PERIMETER_H
#define CHAPTER8__Q463_ISLAND_PERIMETER_H

#include <vector>

using namespace std;

 class Solution {
 public:
     int islandPerimeter(vector<vector<int>>& grid) {
         int ncol = grid[0].size(), nrow=grid.size();
         // 每有两个岛屿相邻就会损失两条边，因此周长为 4*island_num - 2*boarder
         int island_num = 0, boader = 0;

         for(int r=0; r<nrow; r++){
             for(int c=0; c<ncol; c++){
                 if(grid[r][c]==1){
                     island_num++;
                     // 当前陆地右边也是陆地
                     if(c+1<ncol && grid[r][c+1]==1) boader++;
                     // 当前陆地下边也是陆地
                     if(r+1<nrow && grid[r+1][c]==1) boader++;
                 }
             }
         }
         return 4*island_num - 2*boader;
     }
 };


class Solution2 {
public:
    int ncol, nrow;
    int ret = 0;
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited;

    int islandPerimeter(vector<vector<int>>& grid) {
        // 回溯深度优先算法，找到所有的递归退出条件：
        // (1) 当前格子不是陆地；（2）到达了边界
        nrow = grid.size(), ncol=grid[0].size();
        for(int i=0;i<nrow;i++) visited.emplace_back(vector<bool>(ncol, false));

        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                if(!visited[r][c] && grid[r][c]==1)
                    dfs(r, c, grid);
            }
        }

        return ret;
    }

    void dfs(int ridx, int cidx, const vector<vector<int>> &grid){
        // 到边界了, 到海洋了
        if(!inArea(ridx, cidx) || grid[ridx][cidx]==0){
            ret++;
            return;
        }

        if(visited[ridx][cidx]) return;

        visited[ridx][cidx] = true;
        for(int i=0; i<4; i++){
            int new_r = ridx + d[i][0];
            int new_c = cidx + d[i][1];
            dfs(new_r, new_c, grid);
        }
    }

    bool inArea(int ridx, int cidx){
        return ridx<nrow && ridx>=0 && cidx<ncol && cidx>=0;
    }

};

#endif //CHAPTER8__Q463_ISLAND_PERIMETER_H
