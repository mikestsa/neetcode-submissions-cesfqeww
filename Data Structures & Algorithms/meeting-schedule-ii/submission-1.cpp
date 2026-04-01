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
        std::multiset<std::pair<int, bool>> s;
        for(auto interval : intervals){
            s.insert({interval.start, true});
            s.insert({interval.end, false});
        }
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
