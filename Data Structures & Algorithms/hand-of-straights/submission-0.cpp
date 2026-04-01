class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> counter;
        int grouped = 0;
        for(int h : hand) counter[h]++;
        for(int h : hand){
            if (counter[h] == 0) continue;
            int current_hand = h;
            while(counter[h - 1] > 0) h--;
            for(int i = 0 ; i < groupSize ; i++){
                grouped++;
                counter[h + i]--;
            }

        }
        return grouped == hand.size();
        
    }
};
