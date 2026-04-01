#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    bool is_cell_unvisited(int r, int c, vector<vector<int>>& grid) {
        // Διόρθωση ορθογραφίας στο όνομα: unvisited
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return false;
        return grid[r][c] == 2147483647; 
    }

    void islandsAndTreasure(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rows = rooms.size();
        int columns = rooms[0].size();
        queue<pair<int, int>> q;

        // Βρίσκουμε όλες τις πύλες (0) και τις βάζουμε στην ουρά
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                if (rooms[r][c] == 0) q.push({r, c});
            }
        }

        int distance = 0;
        while (!q.empty()) {
            distance++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur_row = q.front().first;
                int cur_col = q.front().second;
                q.pop();

                for (auto dir : directions) {
                    int neib_row = cur_row + dir.first;
                    int neib_col = cur_col + dir.second; // Η ΔΙΟΡΘΩΣΗ ΕΔΩ

                    if (is_cell_unvisited(neib_row, neib_col, rooms)) {
                        rooms[neib_row][neib_col] = distance;
                        q.push({neib_row, neib_col});
                    }
                }
            }
        }
    }
};