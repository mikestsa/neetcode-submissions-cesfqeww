class MinStack {
public:
    std::vector<std::pair<int, int>> s;
    int min = INT_MAX;
    MinStack() {
  
    }
    
    void push(int val) {
        min = std::min(min, val);
        s.push_back({val, min});    
    }
    
    void pop() {
        s.pop_back();
        if (s.empty()) min = INT_MAX;
        else min = s.back().second;
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};
