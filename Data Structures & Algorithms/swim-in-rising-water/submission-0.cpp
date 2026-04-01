class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         vector<std::pair<int , int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        using PIPI = std::pair<int, std::pair<int, int>>;

        std::priority_queue<PIPI, std::vector<PIPI>, std::greater<PIPI>> minHeap;
        int rows = grid.size();
        int columns = grid[0].size();
        std::vector<std::vector<int>> minCost(rows, std::vector<int>(columns, INT_MAX));
        minHeap.push({grid[0][0], {0,0}});
        while (minHeap.size()){
            auto curr = minHeap.top();
            minHeap.pop();

            int curr_row = curr.second.first;
            int curr_col = curr.second.second;
            int cost = curr.first;
            minCost[curr_row][curr_col] = cost;
            if (curr_row == rows -1 && curr_col == columns -1) return cost;

            for(auto dir: directions){
                int neib_row = curr_row + dir.first;
                int neib_col = curr_col + dir.second;
                if (neib_row >= 0 && neib_col >=0 && neib_row < rows && neib_col < columns){
                    if (minCost[neib_row][neib_col] > max(grid[neib_row][neib_col], cost)){
                        minHeap.push({max(grid[neib_row][neib_col], cost), {neib_row, neib_col}});
                    }
                }
            }
        }
        return 0;
        
    }
};
