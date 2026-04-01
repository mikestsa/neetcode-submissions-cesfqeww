class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        for(auto price : prices){
            min = std::min(price, min);
            max = std::max(max, price - min);
        }
        return max;
        
    }
};
