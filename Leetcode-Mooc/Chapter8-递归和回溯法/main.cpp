#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int ret = 0;
    vector<vector<int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited;

    int islandPerimeter(vector<vector<int>>& grid) {
        // 回溯深度优先算法，找到所有的递归退出条件：
        // (1) 当前格子不是陆地；（2）到达了边界
        int nrow = grid.size();
        int ncol = grid[0].size();
        for(int i=0;i<nrow;i++) visited.emplace_back(vector<bool>(ncol, false));

        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                if(!visited[r][c] && grid[r][c]==1)
                    dfs(r, c, ncol, nrow, grid);
            }
        }

        return ret;
    }

    void dfs(int ridx, int cidx, int ncol, int nrow,const vector<vector<int>> &grid){
        // 到边界了, 到海洋了
        if(!inArea(ridx, cidx, ncol, nrow)){
            ret++;
            return;
        }

        if(grid[ridx][cidx]==0){
            ret++;
            return;
        }

        if(visited[ridx][cidx]==1){
            return;
        }

        visited[ridx][cidx] = 1;

        for(int i=0; i<4; i++){
            int new_r = ridx + d[i][0];
            int new_c = cidx + d[i][1];
            dfs(new_r, new_c, ncol, nrow, grid);
        }
    }

    bool inArea(int ridx, int cidx, int ncol, int nrow){
        return ridx<nrow && ridx>=0 && cidx<ncol && cidx>=0;
    }
};






int main() {
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};

    Solution sol;
    int n = sol.islandPerimeter(grid);
    cout << n;
    return 0;
}