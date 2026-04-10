class CountSquares {
public:
unordered_map<int, unordered_map<int, int>> x_ys;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        x_ys[x][y]++;
        
    }


    //(x, y_other)     
    //(x,y)
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int out = 0;
        for(auto [y_other, count] : x_ys[x]){
            int dist =  abs(y - y_other);
            if (dist == 0) continue;
            int x1 = x - dist;
            int x2 = x + dist;
            out += count*x_ys[x1][y]*x_ys[x1][y_other];
            out += count*x_ys[x2][y]*x_ys[x2][y_other];
        }
        return out;
        
    }
};
