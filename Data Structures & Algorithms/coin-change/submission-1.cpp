class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 ) return 0;
        vector<int> table(amount + 1, INT_MAX);
        for(int coin : coins){
            if (coin >= table.size()) continue;
            table[coin] = 1;
            for(int i = 0 ; i < table.size() ; i++){
                if (table[i] != INT_MAX){
                    if (i + coin < table.size()){
                        table[i + coin] = min(table[i + coin], table[i] + 1);
                    }
                }
            }
        }
        if (table.back() == INT_MAX) return -1;
        return table.back();
        
    }
};
