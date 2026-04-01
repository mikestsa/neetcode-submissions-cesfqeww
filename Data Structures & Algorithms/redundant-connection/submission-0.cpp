class Solution {
public:
    // first = parent, second = rank
    vector<pair<int, int>> parents;

    int root_of(int a) {
        // Σωστό Path Compression (Αναδρομικά)
        if (parents[a].first != a) {
            parents[a].first = root_of(parents[a].first);
        }
        return parents[a].first;
    }

    bool unionn(int a, int b) {
        int root_a = root_of(a);
        int root_b = root_of(b);
        
        if (root_a == root_b) return false; // Ανήκουν ήδη στο ίδιο set (Κύκλος!)
        
        // Union by Rank: Ενώνουμε το μικρότερο δέντρο κάτω από το μεγαλύτερο
        if (parents[root_a].second < parents[root_b].second) {
            parents[root_a].first = root_b;
        } 
        else if (parents[root_a].second > parents[root_b].second) {
            parents[root_b].first = root_a;
        } 
        else {
            parents[root_a].first = root_b;
            parents[root_b].second++; // Προσοχή: Αυξάνουμε το rank της ΡΙΖΑΣ
        }
        
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parents.resize(n + 1);
        
        // Αρχικοποίηση: Κάθε κόμβος είναι γονιός του εαυτού του με rank 0
        for(int i = 0; i <= n; i++){
            parents[i] = {i, 0};
        }

        // Επεξεργασία ακμών
        for(auto& edge : edges) {
            if (!unionn(edge[0], edge[1])) {
                return edge; // Η ακμή που κλείνει τον κύκλο
            }
        }
        
        return {};
    }
};