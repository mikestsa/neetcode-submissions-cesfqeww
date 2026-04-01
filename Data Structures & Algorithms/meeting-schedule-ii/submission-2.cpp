/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::vector<std::pair<int, bool>> s;
        for(auto interval : intervals){
            s.push_back({interval.start, true});
            s.push_back({interval.end, false});
        }
        std::sort(s.begin(), s.end());
        int curr = 0;
        int max = 0;
        for(auto p : s){
            if (p.second) curr++;
            else curr--;
            max = std::max(max, curr);
        }
        return max;
        
    }
};
