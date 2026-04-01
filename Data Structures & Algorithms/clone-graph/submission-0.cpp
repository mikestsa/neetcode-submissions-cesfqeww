/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> old_new;
public:
    Node* get_copy(Node* node){
        if (!node) return nullptr;
        if (old_new.find(node) == old_new.end()){
            Node* copy = new Node(node->val);
            old_new[node] = copy;

            for(auto neib : node->neighbors){
                copy->neighbors.push_back(get_copy(neib));
            }
        }
        return old_new[node];        
        
    }

    Node* cloneGraph(Node* node) {
        std::queue<Node*> q;
        if (!node) return node;
        q.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        while(q.size()){
            auto curr = q.front();
            get_copy(curr);
            q.pop();
            for(auto neib : curr->neighbors){
                if (visited.find(neib) == visited.end()){
                    q.push(neib);



                    visited.insert(neib);
                }
            }
        }
        return get_copy(node);
        
    }
};
