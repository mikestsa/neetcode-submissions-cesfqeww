class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int out = 0;
        std::vector<std::pair<int, int>> position_speed;
        for(int i = 0 ;  i < position.size() ; i++){
            position_speed.push_back({position[i], speed[i]});
        }
        std::sort(position_speed.begin(), position_speed.end());
        double prev_arrival = 00000000;
        for(int i = position_speed.size() - 1 ; i >= 0 ; i--){
            int position = position_speed[i].first;
            int speed = position_speed[i].second;
            double arrival_time = ((double)target - (double)position)/(double)speed;
            arrival_time = max(arrival_time, prev_arrival);
            if (arrival_time != prev_arrival) out+=1;
            prev_arrival = arrival_time;

        }        
        return out;
        
    }
};
