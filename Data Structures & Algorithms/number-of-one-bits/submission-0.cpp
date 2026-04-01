class Solution {
public:
    int hammingWeight(uint32_t n) {
        int out = 0;
        while(n){
             out += n&1;
             n = n>>1;
        }
        return out;

    }
};
