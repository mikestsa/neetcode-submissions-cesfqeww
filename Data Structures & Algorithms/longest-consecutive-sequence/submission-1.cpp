class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> s;
        for(int num : nums) s[num]++;
        int maxx = 0;
        for( auto& [num, count] : s){
            if (count > 0){
                count = 0;
                int temp = num;
                int counter = 1;

                while( s.count(--temp) && s[temp] > 0){
                    counter++;
                    s[temp] = 0;
                }
                temp = num;

                while(  s.count(++temp) &&  s[temp] >0){
                    counter++;
                    s[temp] =0;
                }
                maxx = max(maxx, counter);
            }
        }

        return maxx;


    }
};
