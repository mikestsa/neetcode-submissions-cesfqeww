class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0 ; i < coins.size(); i++){
            int current = coins[i];
            for(int j = 0 ; j < dp.size() ; j++){
                if (j + current < dp.size()){
                    dp[j + current] +=dp[j];
                }
            }
        }

        return dp.back();
        
    }
};
