class Solution {
        unordered_map<string, std::map<string, int>> m;
        int total_routes;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        total_routes = tickets.size() + 1;
        for(auto ticket : tickets){
            string from = ticket[0];
            string to = ticket[1];
            m[from][to]++;
        }
      
        string current = "JFK";

        std::vector<string> out ;
        out.push_back(current);
        findItinerary(1, current, out);     
        return out;   
    }

    bool findItinerary(int i, string current, std::vector<string>& out ) {
        if (out.size() == total_routes) return true;
        for(auto& [key, data] : m[current]){
            if (data == 0) continue;
            string destination = key;
            out.push_back(destination);
            data--;
            if (findItinerary(i + 1, destination, out)){
                return true;
            }
            data++;
            out.pop_back();
        }
        return false;
        
        
        
    }
};
