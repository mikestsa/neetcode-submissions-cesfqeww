#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Διασφαλίζουμε ότι το nums1 είναι το μικρότερο για να ελαχιστοποιήσουμε το range του binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // 0 1 2 3 4 -> 2
        // 0 3 4 5 6 7 8 9 ->

        while (left <= right) {
            int partitionX = left + (right - left) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX; 

            // Αν partitionX == 0, δεν υπάρχουν στοιχεία αριστερά στο nums1. Χρησιμοποιούμε INT_MIN
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Βρήκαμε τη σωστή τομή
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) {
                // Είμαστε πολύ δεξιά στο nums1, πάμε αριστερά
                right = partitionX - 1;
            } 
            else {
                // Είμαστε πολύ αριστερά στο nums1, πάμε δεξιά
                left = partitionX + 1;
            }
        }

        return 0.0;
    }
};