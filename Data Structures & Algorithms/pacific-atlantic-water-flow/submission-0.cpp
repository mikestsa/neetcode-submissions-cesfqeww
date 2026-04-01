class Solution {
public:

    vector<vector<int>> fill_matrix(vector<vector<int>>& heights, std::queue<std::pair<int, int>>& q){
        int R = heights.size();
        int C = heights[0].size();

        vector<std::pair<int , int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::vector<std::vector<int>> matrix(R, std::vector<int>(C, 0));
        while(q.size()){
            auto [r, c] = q.front();
            q.pop();
            matrix[r][c] = 1;
            for(auto dir: directions){
                int neib_row = r + dir.first;
                int neib_col = c + dir.second;
                if (neib_row >= 0 && neib_col >=0 && neib_row < R && neib_col < C){
                    if (matrix[neib_row][neib_col] == 0 && heights[neib_row][neib_col] >= heights[r][c]){
                        matrix[neib_row][neib_col] == 1;
                        q.push({neib_row, neib_col});

                    }
                }
            }

        }

        return matrix;

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        queue<std::pair<int, int>> q;
        for(int r = 0 ; r < R; r++){
            q.push({r , 0});
        }
        for(int c = 1 ; c < C; c++){
            q.push({0 , c});
        }
        auto pacific = fill_matrix(heights, q);
        
        for(int r = 0; r < R; r++){
            q.push({r , C - 1});
        }
        for(int c = 0 ; c < C - 1; c++){
            q.push({R - 1 , c});
        }
        auto atlantic = fill_matrix(heights, q);

        vector<vector<int>> out;
        for(int r = 0 ; r < R ; r++){
            for(int c = 0 ; c < C; c++){
                if (atlantic[r][c] && pacific[r][c]){
                    std::vector<int> curr = {r, c};
                    out.push_back(curr);
                }
            }
        }
        return out;
    }


};
