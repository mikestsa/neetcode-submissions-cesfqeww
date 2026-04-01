class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int min = INT_MAX;
        int index = -1;
        int curr = 0;
        for(int i = 0 ; i<gas.size(); i++){
            curr += gas[i];
            curr -=cost[i];

            if (curr < min){
                min = curr;
                index = i;
            }
        }
        if (curr < 0) return -1;
        if (index == gas.size() - 1) return 0;
        return index + 1;

        
    }
};
