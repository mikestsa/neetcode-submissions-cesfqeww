class TimeMap {
public:
        std::unordered_map<string, std::map<int, string>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
        
    }
    
    string get(string key, int timestamp) {
        auto& un_map =  m[key];
          auto it = un_map.upper_bound( timestamp);
          if (it != un_map.begin()) it--;
          else return "";
          return it->second;
    }
};
