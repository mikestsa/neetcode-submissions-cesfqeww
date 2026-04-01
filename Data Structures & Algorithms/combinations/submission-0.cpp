class Solution {
public:

    void helper(int i, int n, int k, vector<int>& current, vector<vector<int>>& res){
        if (current.size() == k){
            res.push_back(current);
            return;
        }
        if (i > n) return;
        current.push_back(i);
        helper(i +1, n, k, current, res);
        current.pop_back();
        helper(i +1, n, k, current, res);


    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        helper(1, n, k , current, res);
        return res;

        
    }
};