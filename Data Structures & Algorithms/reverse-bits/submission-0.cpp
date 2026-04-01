class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0 ; i < 16 ; i ++){
            int symmetric_index = 31 - i;
            if (((n>>i) & 1 ) != ((n>>symmetric_index)&1)){
                n ^= (1<<i);
                n ^= (1<<symmetric_index);
            }
        }
        return n;
        
    }
};
