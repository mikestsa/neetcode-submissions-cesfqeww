class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int one = 1, two = 2;

        for (int i = 2; i < n; i++) {
            int temp = one + two;
            one = two;
            two = temp;
        }

        return two;
    }
};