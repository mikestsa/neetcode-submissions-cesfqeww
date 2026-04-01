class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() < 2) return arr.size();
        int flag;
        if (arr[0] < arr[1]) flag = 1;
        else if (arr[0] > arr[1]) flag = -1;
        else flag = 0;

        int cur = 1;
        int max = 1;
        if (flag){
            cur = 2;
            max = 2;
        }
        for(int i = 2; i < arr.size(); i++){
            if (arr[i] > arr[i - 1]){
                if (flag == -1 ){
                    cur++;
                }
                else{
                    cur = 2;
                }
                flag = 1;
            }
            else if (arr[i] < arr[i-1]){
                if (flag == 1 ){
                    cur++;
                }
                else{
                    cur = 2;
                    
                }
                flag = -1;

            }
            else{
                flag = 0;
                cur = 1;
            }
            max = std::max(max, cur);
        }
        return max;
    }
};