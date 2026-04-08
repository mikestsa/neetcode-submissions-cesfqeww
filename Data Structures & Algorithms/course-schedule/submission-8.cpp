class Solution {
    vector<vector<int>> adj;
    vector<int> state; // 0: unvisited, 1: visiting, 2: safe

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, vector<int>());
        state.assign(numCourses, 0);

        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i)) return false;
        }
        return true;
    }

    bool hasCycle(int node) {
        if (state[node] == 1) return true; // Κύκλος!
        if (state[node] == 2) return false; // Ήδη ελεγμένο και ασφαλές

        state[node] = 1; // "Μπαίνω" στο μονοπάτι

        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor)) return true;
        }

        state[node] = 2; // "Βγαίνω" και το μαρκάρω ως ασφαλές (αντί για clear)
        return false;
    }
};