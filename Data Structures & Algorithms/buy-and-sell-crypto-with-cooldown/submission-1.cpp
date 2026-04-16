class Solution {
public:
std::unordered_map<int, int> m;
    int maxProfit(vector<int>& prices) {
        return max(maxProfit(prices, 1, true) - prices[0], maxProfit(prices, 1, false));
    }

    int maxProfit(vector<int>& prices, int i, bool own) {
        if( i >= prices.size()) return 0;
        if (own){
            if (m.find(-i) != m.end()) return m[-i];
            m[-i] =  max(maxProfit(prices, i + 2, false) + prices[i], maxProfit(prices, i+1, true)); 
            return m[-i];
        }
        else{
            if (m.find(i) != m.end()) return m[i];
            m[i] = max(maxProfit(prices, i+1, true) - prices[i],maxProfit(prices, i+1, false));
            return m[i];
        }
        
    }
};
