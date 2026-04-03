class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool first_col_has_zero = false;
        bool first_row_has_zero = false;
        for(int r = 0 ; r < rows; r++){
            if (matrix[r][0] == 0) first_col_has_zero = true;
        }
        for(int c = 0 ; c < cols; c++){
            if (matrix[0][c] == 0) first_row_has_zero = true;
        }

        for(int r = 0; r < rows ; r++ ){
            for(int c = 0 ; c < cols ; c++){
                if (matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }

            }
        }

        for(int r = 1; r < rows ; r++ ){
            for(int c = 1 ; c < cols ; c++){
                if (matrix[0][c] == 0 || matrix[r][0] == 0){
                    matrix[r][c] = 0;
                }

            }
        }
        for(int r = 0 ; r < rows; r++){
            if (first_col_has_zero)
            matrix[r][0] = 0;
        }

        for(int c = 0 ; c < cols; c++){
            if (first_row_has_zero)
            matrix[0][c] = 0;
        }
    }
};
