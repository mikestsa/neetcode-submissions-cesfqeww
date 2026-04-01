class Solution {
public:
    int rows = 0;
    int cols = 0;

    std::pair<int,int> get_r_c_from(int v){
        int r = v/cols;
        int c = v%cols;
        return {r,c};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        rows = matrix.size();
        cols = matrix[0].size();

        int left = 0;
        int right = rows*cols -1;
        while(left <= right){
            int mid = left + (right - left )/2;
            auto [r, c] = get_r_c_from(mid);
            if(matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) left = mid + 1;
            else right = mid -1;
        }
        return false;
        
    }
};
