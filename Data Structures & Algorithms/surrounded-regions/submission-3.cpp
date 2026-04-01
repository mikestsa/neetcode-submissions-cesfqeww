class Solution {
public:
    struct Team{
        int min_row;
        int max_row;
        int min_col;
        int max_col;
        std::vector<std::pair<int, int>> cells;
    };
    void solve(vector<vector<char>>& board) {
        vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<Team> teams;
        int R = board.size();
        int C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));


        for(int r = 0 ; r < R; r++){
            for (int c = 0 ; c < C ; c++){
                if (board[r][c] == 'O' && visited[r][c] == false){
                    Team team;
                    queue<std::pair<int, int>> q;
                    q.push({r, c});
                    team.cells.push_back({r,c});
                    team.min_row = r;
                    team.max_row = r;
                    team.min_col = c;
                    team.max_col = c;
                    while(q.size()){
                        auto [cr, cc] = q.front();
                        q.pop();
                        for(auto dir : directions){
                            int neib_row = cr + dir.first;
                            int neib_col = cc + dir.second;
                            if (neib_row >= 0 && neib_col >= 0 && neib_col < C && neib_row < R){
                                if (board[neib_row][neib_col]== 'O' &&visited[neib_row][neib_col] == false){
                                    visited[neib_row][neib_col] = true;
                                    team.cells.push_back({neib_row, neib_col});
                                    q.push({neib_row, neib_col});
                                    team.min_row = min(team.min_row,neib_row);
                                    team.max_row = max(team.max_row,neib_row);
                                    team.min_col = min(team.min_col,neib_col);
                                    team.max_col = max(team.max_col,neib_col);
                                }
                            }
                        }

                    }
                    if (team.min_row != 0 && team.max_row != (R - 1) && team.min_col != 0 && team.max_col != (C-1)){
                        teams.push_back(team);
                    }
                }
            }
        }
        for(auto &team : teams){
            for(auto &cell : team.cells){
                board[cell.first][cell.second] = 'X';
            }
        }
        
    }
};
