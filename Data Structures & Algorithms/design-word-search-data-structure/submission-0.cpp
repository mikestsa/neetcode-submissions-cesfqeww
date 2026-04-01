class WordDictionary {
public:
    class TrieNode{
        public:
        unordered_map<char, TrieNode*> m;
        bool end = false;
    };

    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(auto c : word){
            if (current->m.find(c) == current->m.end()){
                current->m[c] = new TrieNode();
            }
            current = current->m[c];

        }
        current->end = true;
    }
    
    bool search(string word) {
        std::vector<TrieNode*> current;
        current.push_back(root);
        for(auto c : word){
            std::vector<TrieNode*> new_current;

            if (c == '.'){
                for(auto trie : current){
                    for(const auto& [key, data] : trie->m){
                        new_current.push_back(data);
                    }
                }

            }
            else{
                for(auto trie : current){
                    if (trie->m.find(c) != trie->m.end()){
                        new_current.push_back(trie->m[c]);
                    }
                }
            }
            current = new_current;
            
        }
        return std::any_of(current.begin(), current.end(),[](TrieNode* node){
            return node->end;
        });
        
    }
};
