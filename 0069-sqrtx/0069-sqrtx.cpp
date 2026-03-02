class Solution {
public:
    int mySqrt(int x) {

        if (x == 0 || x == 1)
            return x;

        long low = 1, high = x;
        long ans = 0;

        while (low <= high) {

            long mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;        // possible answer
                low = mid + 1;    // try bigger
            } 
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};