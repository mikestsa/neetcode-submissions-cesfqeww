class Solution {
public:
    int ROWS;
    int COLS;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> get_neibs(int row, int col){
        vector<vector<int>> out;
        for(auto dir : directions){
            int r = row + dir[0];
            int c = col + dir[1];
            if (is_valid(c,r)) out.push_back({r,c}); 
        }
        return out;
    }

    bool is_valid(int row, int col){
        return row>= 0 && row < ROWS && col >=0 && col < COLS;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0));
        for(int r = 0 ; r < ROWS; r++){
            for(int c = 0 ; c < COLS; c++){
                int row_of_left = r;
                int col_of_left = c + 1;
                if (is_valid(row_of_left, col_of_left)){
                    if (matrix[r][c] > matrix[row_of_left][col_of_left]){
                        indegree[r][c]++;
                    }
                    else if(matrix[r][c] < matrix[row_of_left][col_of_left]){
                        indegree[row_of_left][col_of_left]++;
                    }
                }
                int row_of_down = r + 1;
                int col_of_down = c;
                if (is_valid(row_of_down, col_of_down)){
                    if (matrix[r][c] > matrix[row_of_down][col_of_down]){
                        indegree[r][c]++;
                    }
                    else if(matrix[r][c] < matrix[row_of_down][col_of_down]){
                        indegree[row_of_down][col_of_down]++;
                    }
                }

            }
        }
        queue<std::pair<int, int>> q;
        for(int r = 0 ; r < ROWS; r++){
            for (int c = 0 ; c < COLS ; c++){
                if (indegree[r][c] == 0) q.push({r, c});
            }
        }
         int LIS = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 &&
                        nc < COLS && matrix[nr][nc] > matrix[r][c]) {
                        if (--indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
            LIS++;
        }
        return LIS;
        
    }
};
