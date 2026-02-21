class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int Aleft  = (i == 0) ? INT_MIN : nums1[i-1];
            int Aright = (i == m) ? INT_MAX : nums1[i];

            int Bleft  = (j == 0) ? INT_MIN : nums2[j-1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {

                if ((m + n) % 2 == 0) {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                } else {
                    return max(Aleft, Bleft);
                }

            } 
            else if (Aleft > Bright) {
                high = i - 1;
            } 
            else {
                low = i + 1;
            }
        }

        return 0.0; // never reaches
    }
};