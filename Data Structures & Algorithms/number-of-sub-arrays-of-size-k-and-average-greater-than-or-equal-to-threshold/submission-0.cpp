class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if (k > arr.size()) return 0;
        int left = 0;
        int sum = 0;
        int total = 0;
        for(int i = 0 ; i < k ; i++){
            sum += arr[i];
        }
        int right = k - 1;
        while(right < arr.size()){
            
            if (sum/k >= threshold) total++;
            sum -= arr[left];
            left++;
            right++;
                        if (right < arr.size()) sum += arr[right];

           
        }
        return total;
        
    }
};