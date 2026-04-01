class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Η στοίβα κρατάει ζεύγη: {ύψος, αρχικό_index_από_το_οποίο_ξεκινάει_αυτό_το_ύψος}
        stack<pair<int, int>> height_index_stack; 
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int curr_height = heights[i];
            int index_new = i;
    
            // Όσο το τρέχον ύψος είναι μικρότερο από την κορυφή της στοίβας,
            // κάνουμε pop και υπολογίζουμε το εμβαδόν για το ύψος που αφαιρούμε.
            while (!height_index_stack.empty() && height_index_stack.top().first >= curr_height) {
                auto [prev_height, prev_index] = height_index_stack.top();
                height_index_stack.pop();
                
                // Υπολογισμός εμβαδού: το πλάτος είναι από το prev_index μέχρι το i
                max_area = max(max_area, (i - prev_index) * prev_height);
                
                // Το τρέχον μικρότερο ύψος μπορεί να επεκταθεί προς τα αριστερά, 
                // ξεκινώντας από το index του στοιχείου που μόλις κάναμε pop.
                index_new = prev_index;
            }
            
            height_index_stack.push({curr_height, index_new});
        }

        // Αδειάζουμε τη στοίβα. Ό,τι έμεινε, εκτείνεται μέχρι το τέλος του πίνακα (n).
        while (!height_index_stack.empty()) {
            auto [height, index] = height_index_stack.top();
            height_index_stack.pop();
            
            // Το πλάτος τώρα είναι (n - index)
            max_area = max(max_area, (n - index) * height);
        }

        return max_area;
    }
};