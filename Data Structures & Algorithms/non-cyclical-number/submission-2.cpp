class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> visited;
        visited.insert(n);
        while(n != 1){
            int new_n = 0;
            while(n > 0){
                new_n += (n%10)*(n%10);
                n /= 10;
            }

            n = new_n;
            if ( n == 1) return true;
            if (visited.find(n) != visited.end()) return false;
            visited.insert(n);
        }      
        return false;
    }
};
