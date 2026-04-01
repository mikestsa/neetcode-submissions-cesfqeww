class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        result.resize(temperatures.size());
        stack<pair<int,int>> stack; //index temperature
        // i want decreasing stack always
        for(int i = 0 ; i < temperatures.size() ; i++){
            while(stack.size() && stack.top().second < temperatures[i]){
                auto [index, temp] = stack.top();
                stack.pop();
                result[index] = i - index;
            }
            stack.push({i, temperatures[i]});
        }
        return result;
        
    }
};
