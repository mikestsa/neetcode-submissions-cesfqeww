class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> out;
        
        for (int i = 0; i < nums.size(); i++) {
            // Βγάζουμε από μπροστά στοιχεία που δεν ανήκουν πια στο παράθυρο
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Βγάζουμε από πίσω στοιχεία που είναι μικρότερα από το νέο στοιχείο, 
            // γιατί πλέον είναι άχρηστα (δεν πρόκειται ποτέ να είναι το μέγιστο)
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Προσθέτουμε το index του νέου στοιχείου
            dq.push_back(i);
            
            // Το μεγαλύτερο στοιχείο του τρέχοντος παραθύρου είναι πάντα μπροστά
            if (i >= k - 1) {
                out.push_back(nums[dq.front()]);
            }
        }
        return out;
    }
};