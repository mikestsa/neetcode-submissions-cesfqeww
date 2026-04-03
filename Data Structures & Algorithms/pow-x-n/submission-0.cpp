class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double multiply_at_end = 1;
        double res = x;
        bool negative = n > 0 ? false : true;
        long long int new_n  = n;
        new_n = abs(new_n);
        while(new_n > 1){
            if (new_n%2) {
                multiply_at_end *= res;
                new_n--;
            }
            else{
                 res *=res;
                 new_n /=2;

            }
           
        }
        double out =  multiply_at_end*res;
        if (negative) return 1.0/out;
        return out;
        
    }
};