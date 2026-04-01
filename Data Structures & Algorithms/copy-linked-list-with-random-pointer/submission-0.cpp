/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_new;
        Node* node = head;
        while(node){
            old_new[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while(node){
            Node* copy = old_new[node];
            copy->next = old_new[node->next];
            copy->random = old_new[node->random];
            node = node->next;
        }
        return old_new[head];
        
    }
};
