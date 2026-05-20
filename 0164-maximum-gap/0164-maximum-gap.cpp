class Solution {
public:

    // Counting sort for one digit place
    void countingSort(vector<int>& nums, int exp) {

        int n = nums.size();

        vector<int> output(n);
        vector<int> count(10, 0);

        // Store frequency of digits
        for(int i = 0; i < n; i++) {

            int digit = (nums[i] / exp) % 10;
            count[digit]++;
        }

        // Convert into prefix sums
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build output array (reverse traversal for stability)
        for(int i = n - 1; i >= 0; i--) {

            int digit = (nums[i] / exp) % 10;

            output[count[digit] - 1] = nums[i];

            count[digit]--;
        }

        // Copy back
        nums = output;
    }

    int maximumGap(vector<int>& nums) {

        // Edge case
        if(nums.size() < 2) {
            return 0;
        }

        int n = nums.size();

        // Find maximum element
        int maxi = nums[0];

        for(int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        // Radix sort
        for(long long exp = 1; maxi / exp > 0; exp *= 10) {
            countingSort(nums, exp);
        }

        // Find maximum adjacent difference
        int ans = 0;

        for(int i = 1; i < n; i++) {

            ans = max(ans, nums[i] - nums[i - 1]);
        }

        return ans;
    }
};