class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;

            if (count.size() > 2) {
                for (auto it = count.begin(); it != count.end(); it++) {
                    if (it->second > 1) {
                        it->second--;
                        if (it-> second <= 0) it = count.erase(it);
                    }
                }
            }
        }

        vector<int> res;
        for (auto& entry : count) {
            int frequency = 0;
            for (int num : nums) {
                if (num == entry.first) frequency++;
            }
            if (frequency > nums.size() / 3) {
                res.push_back(entry.first);
            }
        }

        return res;
    }
};