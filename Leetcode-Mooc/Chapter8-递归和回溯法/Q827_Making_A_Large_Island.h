//
// Created by shexuan on 2021/3/3.
//

#ifndef CHAPTER8__Q827_MAKING_A_LARGE_ISLAND_H
#define CHAPTER8__Q827_MAKING_A_LARGE_ISLAND_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nrow, ncol, area, island_idx;
    vector<vector<bool>> visited;
    unordered_map<int, int> area_mp;
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int largestIsland(vector<vector<int>>& grid) {
        nrow = grid.size(), ncol = grid[0].size();
        visited = vector<vector<bool>>(nrow, vector<bool>(ncol, false));
        // 先计算出所有的岛屿的大小
        island_idx = 2; // 标记岛屿群从2开始
        int max_area = 0;
        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                area = 0; // 每一个新岛屿重新计算面积
                if(!visited[r][c] && grid[r][c]==1){
                    dfs(r, c, grid);
                    area_mp[island_idx] = area;
                    island_idx++; // 每一片岛屿一个idx
                    max_area = max(max_area, area);
                }
            }
        }

        area_mp[0] = 0; // 海洋的陆地面积为0

        // 将每一个0置为1然后计算最大岛屿数量
        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                // 海洋变为陆地后加上四周陆地岛屿面积
                int around_area = 0;
                if(grid[r][c]==0){
                    // 四周岛屿面积
                    unordered_set<int> island_set;
                    for(int i=0;i<4;i++){
                        int new_r = r + d[i][0];
                        int new_c = c + d[i][1];
                        if(inArea(new_r, new_c) && island_set.find(grid[new_r][new_c])==island_set.end()){
                            island_set.insert(grid[new_r][new_c]);
                            around_area += area_mp[grid[new_r][new_c]];
                        }
                    }
                    max_area = max(max_area, 1+around_area);
                }
            }
        }

        return max_area;
    }


    void dfs(int ridx, int cidx, vector<vector<int>>& grid){
        if(!inArea(ridx, cidx) || grid[ridx][cidx]==0 || visited[ridx][cidx])
            return;

        area++;
        grid[ridx][cidx] = island_idx; // 标记该片岛屿名字
        visited[ridx][cidx] = true;

        for(int i=0;i<4;i++){
            int new_r = ridx + d[i][0];
            int new_c = cidx + d[i][1];
            dfs(new_r, new_c, grid);
        }
    }

    bool inArea(int ridx, int cidx){
        return ridx<nrow && ridx>=0 && cidx>=0 && cidx<ncol;
    }
};
#endif //CHAPTER8__Q827_MAKING_A_LARGE_ISLAND_H
