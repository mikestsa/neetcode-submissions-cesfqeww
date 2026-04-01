#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Διόρθωση: Προσθήκη '>' που έλειπε στο template
        unordered_map<int, vector<pair<int, int>>> f_from_to_cost;
        
        for(auto& flight : flights){
            f_from_to_cost[flight[0]].push_back({flight[1], flight[2]});
        }

        // 2. Διόρθωση: Το greater πρέπει να έχει τον ίδιο τύπο (tuple) με την ουρά
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        minHeap.push({0, src, 0});
        
        while(minHeap.size()){
            auto curr = minHeap.top();
            minHeap.pop();
            
            // 3. Διόρθωση: Στο tuple δεν δουλεύει το [], χρησιμοποιούμε get<index>
            int curr_cost = get<0>(curr);
            int curr_dest = get<1>(curr);
            int curr_total_dests = get<2>(curr);
            
            if (curr_dest == dst) return curr_cost;
            
            // Προσοχή: Εδώ ο Dijkstra σταματάει αν ξεπεράσουμε τα k stops
            if (curr_total_dests > k) continue;

            for(auto& p : f_from_to_cost[curr_dest]){
                int dest = p.first;
                int cost = p.second;
                int total_stops = curr_total_dests + 1;
                
                // 4. Διόρθωση: Το όνομα ήταν minHeap (όχι heap) και η μεταβλητή total_stops (όχι curr_to)
                minHeap.push({curr_cost + cost, dest, total_stops});
            }
        }
        return -1;        
    }
};