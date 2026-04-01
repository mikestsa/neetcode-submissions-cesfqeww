class PrefixTree {
public:


    class TrieNode{
        public:
        unordered_map<char, TrieNode*> m;
        bool endOfWord = false;
    };

    TrieNode* root;


    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {

        if (word.empty()) return;
        TrieNode* current = root;
        for(char c : word){
            if (current->m.find(c) == current->m.end()){
                current->m[c] = new TrieNode();
            }
            current = current->m[c];
        }
        current->endOfWord = true;        
        
    }
    
    bool search(string word) {
           if (word.empty()) return false;
        TrieNode* current = root;
        for(char c : word){
            if (current->m.find(c) == current->m.end()){
                return false;
            }
            current = current->m[c];
        }
        return current->endOfWord;  
        
    }
    
    bool startsWith(string prefix) {
            if (prefix.empty()) return false;
        TrieNode* current = root;
        for(char c : prefix){
            if (current->m.find(c) == current->m.end()){
                return false;
            }
            current = current->m[c];
        }
        return true;  
        
    }
};
