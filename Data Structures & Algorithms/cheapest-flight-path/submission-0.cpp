#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Διόρθωση: Κλείσιμο του > στο map
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto& flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Priority Queue: {cost, current_node, stops_made}
        // Χρησιμοποιούμε tuple<int, int, int> και το default greater για min-heap
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        minHeap.push({0, src, 0});

        // Προσθήκη ενός array για να παρακολουθούμε το ελάχιστο πλήθος στάσεων 
        // για να φτάσουμε σε έναν κόμβο (βελτιώνει το performance και αποφεύγει κύκλους)
        vector<int> stops(n, numeric_limits<int>::max());

        while(!minHeap.empty()){
            auto [curr_cost, u, curr_stops] = minHeap.top();
            minHeap.pop();

            // Αν φτάσαμε στον προορισμό, επειδή είναι min-heap, αυτό είναι το φθηνότερο
            if (u == dst) return curr_cost;

            // Αν έχουμε ήδη κάνει k στάσεις (k stops σημαίνει k+1 flights max)
            // ή αν έχουμε βρει ήδη δρόμο για τον 'u' με λιγότερες στάσεις, προσπερνάμε
            if (curr_stops > k || curr_stops >= stops[u]) continue;
            
            stops[u] = curr_stops;

            for(auto& edge : adj[u]){
                int v = edge.first;
                int weight = edge.second;
                minHeap.push({curr_cost + weight, v, curr_stops + 1});
            }
        }
        
        return -1;        
    }
};