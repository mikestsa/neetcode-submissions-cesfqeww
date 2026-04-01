class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        // 1. Λίστα γειτνίασης με vector (γρήγορη προσπέλαση αφού οι κόμβοι είναι 0 έως n-1)
        // Κάθε θέση u περιέχει μια λίστα από ζεύγη {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w}); // Κατευθυνόμενος γράφος, άρα μόνο από το u στο v
        }

        // 2. Πίνακας αποστάσεων αρχικοποιημένος στο "Άπειρο"
        // Χρησιμοποιούμε vector για αστραπιαίο update κατά τη διάρκεια του Dijkstra
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // 3. Min-Heap για την ουρά προτεραιότητας: αποθηκεύει ζεύγη {τρέχον_κόστος, κόμβος}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        // 4. Ο αλγόριθμος Dijkstra
        while (!minHeap.empty()) {
            auto [current_cost, u] = minHeap.top();
            minHeap.pop();

            // Αν βγάλαμε από το heap ένα "μπαγιάτικο" / χειρότερο μονοπάτι, το αγνοούμε
            if (current_cost > dist[u]) {
                continue;
            }

            // Ελέγχουμε τους γείτονες του κόμβου u
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                // Αν το νέο μονοπάτι είναι συντομότερο
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    minHeap.push({dist[v], v});
                }
            }
        }

        // 5. Μεταφορά των τελικών αποστάσεων στο unordered_map που ζητάει η εκφώνηση
        unordered_map<int, int> result;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) {
                result[i] = -1; // Ο κόμβος είναι απροσπέλαστος (unreachable)
            } else {
                result[i] = dist[i]; // Βρέθηκε συντομότερο μονοπάτι
            }
        }

        return result;
    }
};