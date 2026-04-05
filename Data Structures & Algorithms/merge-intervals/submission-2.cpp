class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> out;
        std::sort(intervals.begin(), intervals.end());
        if (intervals.size() == 1) return intervals;
        vector<int> current = intervals[0];
        for(int i = 1 ; i < intervals.size(); i++){
            if (current[1] >=intervals[i][0]){
                current[1] = max(current[1], intervals[i][1]);
            }
            else{
                out.push_back(current);
                current = intervals[i];
            }
            if (i == intervals.size() - 1) out.push_back(current);
        }
        return out;
        
    }
};
