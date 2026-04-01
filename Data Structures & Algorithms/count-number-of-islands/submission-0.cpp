class Solution {
public:
    char get_node_val(int r, int c, vector<vector<char>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows || c<0 || c >= cols) return '0';
        return grid[r][c];
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int out = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int r = 0 ; r < rows ; r++ ){
            for(int c = 0 ; c < cols ; c++){
                if (grid[r][c] == '1' ){
                    out++;
                    std::queue<std::pair<int, int>> q;
                    q.push({r, c});
                    while(q.size()){
                        auto cur_node = q.front();
                        q.pop();
                        for(auto dir : directions){
                            int neib_r= cur_node.first + dir.first;
                            int neib_c = cur_node.second + dir.second;
                            if (get_node_val(neib_r, neib_c, grid) == '1'){
                                q.push({neib_r, neib_c});
                                grid[neib_r][neib_c] = '0';

                            }
                        }
                    }
                }
            }
        }
        return out;

        
    }
};
