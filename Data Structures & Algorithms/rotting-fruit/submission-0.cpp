class Solution {
public:
 bool is_fruit_fresh(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return false;
        return grid[r][c] == 1; 
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        std::queue<std::pair<int, int>> q;
        int R = grid.size();
        int C = grid[0].size();
        int remaining_fresh = 0;
        for(int r = 0 ; r < R; r++){
            for(int c = 0 ; c < C ; c++){
                if (grid[r][c] == 2) q.push({r,c});
                else if (grid[r][c] == 1) remaining_fresh++;
            }
        }
        int minutes = 0;
        if (q.size()) minutes--;

        while(q.size()){
           
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto [curr_x, curr_y] = q.front();
                q.pop();
                for(auto dir : directions){
                    int neib_r = dir.first + curr_x;
                    int neib_c = dir.second + curr_y;
                    if (is_fruit_fresh(neib_r, neib_c, grid)) {
                        grid[neib_r][neib_c] = 2;
                        remaining_fresh--;
                        q.push({neib_r, neib_c});
                    }
                }
            }
            minutes++;
        }
        if (remaining_fresh) return -1;
        return minutes;
        
    }
};
