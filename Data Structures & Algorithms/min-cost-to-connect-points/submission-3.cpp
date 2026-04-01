class Solution {
    // Βοηθητική δομή Union-Find
    class UnionFind {
        vector<int> parent;
    public:
        UnionFind(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i; // Αρχικά κάθε σημείο είναι ο εαυτός του
        }
        
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]); // Path compression
        }
        
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) { // Αν ανήκουν σε διαφορετικά γκρουπ, ενωσέ τα
                parent[rootY] = rootX;
                return true;
            }
            return false; // Ανήκουν ήδη στο ίδιο γκρουπ (δημιουργούν κύκλο)
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Χρησιμοποιούμε vector και sort αντί για set, είναι πιο γρήγορο
        vector<pair<int, pair<int, int>>> edges;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }        
        
        // Ταξινομούμε τις ακμές από τη μικρότερη στη μεγαλύτερη (Λογική Kruskal)
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n);
        int out = 0;
        int edgesUsed = 0; // Κρατάμε πόσες ακμές έχουμε προσθέσει
        
        for (auto& edge : edges) {
            int distance = edge.first;
            int point1 = edge.second.first;
            int point2 = edge.second.second;
            
            // Αν μπορούν να ενωθούν (δεν ανήκουν ήδη στο ίδιο γκρουπ)
            if (uf.unite(point1, point2)) {
                out += distance;
                edgesUsed++;
                // Ένα δέντρο με n κόμβους χρειάζεται ακριβώς n-1 ακμές
                if (edgesUsed == n - 1) break; 
            }
        }

        return out;
    }
};