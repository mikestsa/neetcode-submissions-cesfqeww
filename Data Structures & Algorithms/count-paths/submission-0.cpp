class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> row(n, 1);
        for(int i = 0 ; i < m - 1 ; i++){
            row[n - 1] = 1;
            for(int j = n - 2; j>=0; j--){
                row[j] += row[j + 1];
            }
        }
        return row[0];
        
    }
};
