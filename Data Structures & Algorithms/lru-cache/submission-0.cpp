class LRUCache {
public:
    int m_capacity = 0;
    unordered_map<int, std::pair<int, list<int>::iterator>> m;
    std::list<int> l;
    LRUCache(int capacity) {
       m_capacity = capacity; 
    }
    
    int get(int key) {

        if (m.find(key) == m.end()) return -1;
        auto iter = m[key].second;
        l.erase(iter);
        l.push_front(key);
        m[key].second = l.begin();
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()){
            l.erase(m[key].second);
        }
        l.push_front(key);
        m[key] = {value, l.begin()};
        if (m.size() > m_capacity){
            int val_to_remove  = l.back();
            l.pop_back();
            m.erase(val_to_remove);
        }
        
    }
};
