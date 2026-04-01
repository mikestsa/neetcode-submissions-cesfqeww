class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Η ουρά αποθηκεύει pair<τιμή, δείκτης>
        priority_queue<pair<int, int>> q;
        vector<int> out;
        
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i}); // Προσθέτουμε πάντα το νέο στοιχείο
            
            // Αν το μέγιστο στοιχείο είναι πλέον εκτός παραθύρου, το πετάμε
            while (q.top().second <= i - k) {
                q.pop();
            }
            
            // Ξεκινάμε να γράφουμε στο αποτέλεσμα όταν σχηματιστεί το πρώτο πλήρες παράθυρο
            if (i >= k - 1) {
                out.push_back(q.top().first);
            }
        }
        
        return out;
    }
};