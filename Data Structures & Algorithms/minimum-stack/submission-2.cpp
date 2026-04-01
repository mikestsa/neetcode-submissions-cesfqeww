class MinStack {
public:
    std::vector<std::pair<int, int>> s;
    MinStack() {
  
    }
    
    void push(int val) {
        int min = s.size() ? s.back().second : INT_MAX;
        s.push_back({val,std::min(val, min)});    
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};
