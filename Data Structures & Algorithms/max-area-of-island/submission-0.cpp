class Solution {
public:

    bool is_cell_land(int r, int c, vector<vector<int>>& grid){
        if (c <0 || r <0 || r >= grid.size() || c >= grid[0].size()) return false;
        return grid[r][c];
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0; c < cols ; c++){
                if(grid[r][c] == 1){
                    
                    int current_area = 0;
                    queue<pair<int,int>> q;
                    q.push({r,c});
                    grid[r][c] = 0;
                    while(q.size()){
                        auto curr = q.front();
                        q.pop();
                        current_area++;
                        for(auto dir : directions){
                            int neib_row = dir.first + curr.first;
                            int neib_col = dir.second + curr.second;
                            if (is_cell_land(neib_row, neib_col, grid)){
                                q.push({neib_row, neib_col});
                                grid[neib_row][neib_col] = 0;
                            }
                        }
                    }
                    max_area = max(max_area, current_area);
                }
            }
        }
        return max_area;
        
    }
};
