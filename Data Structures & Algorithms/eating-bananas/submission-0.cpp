class Solution {
public:
    int count_hours(int k,vector<int>& piles ){
        int h = 0;
        for(auto pile : piles){
            int hours = pile/k;
            h += hours;
            if ( pile%k) h++;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for(auto pile : piles) max= std::max(max, pile);
        int left = 1;
        int out = INT_MAX;
        int right = max;
        while(left <= right){
            int mid = left + (right - left)/2;
            if (count_hours(mid, piles) <= h){
                out = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }

        }
        return out;
    }
};
