//
// Created by shexuan on 2021/3/2.
//

#ifndef CHAPTER8__Q130_SURROUNDED_REGIONS_H
#define CHAPTER8__Q130_SURROUNDED_REGIONS_H

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int ncol, nrow;

    void solve(vector<vector<char>>& board) {
        // 先从边缘开始查找O，并将所有的O标记为其他符号，然后将剩余的O标记为X，最后将其他符号换回O
        nrow = board.size();
        ncol = board[0].size();

        for(int r=0;r<nrow;r++){
            for(int c=0;c<ncol;c++){
                if((r==0 || c==0 || r==nrow-1 || c==ncol-1) && board[r][c]=='O'){
                    dfs(r, c, board);
                }
            }
        }

        for(int r=0; r<nrow; r++){
            for(int c=0; c<ncol; c++){
                if(board[r][c]=='O'){
                    board[r][c] = 'X';
                }else if(board[r][c]=='#'){ // 将标记的部分改回来
                    board[r][c] = 'O';
                }
            }
        }

    }

    void dfs(int ridx, int cidx, vector<vector<char>>& board){
        board[ridx][cidx] = '#';

        for(int i=0;i<4;i++){
            int new_r = ridx + d[i][0];
            int new_c = cidx + d[i][1];
            if(inArea(new_r, new_c) && board[new_r][new_c]=='O'){
                dfs(new_r, new_c, board);
            }
        }
    }

    bool inArea(int ridx, int cidx){
        return ridx>=0 && ridx<nrow && cidx>=0 && cidx<ncol;
    }
};
#endif //CHAPTER8__Q130_SURROUNDED_REGIONS_H
