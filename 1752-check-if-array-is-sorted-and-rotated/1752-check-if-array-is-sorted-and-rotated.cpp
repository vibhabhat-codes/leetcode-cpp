class Solution {
public:
    bool check(vector<int>& nums) {
         int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Compare current element with next element
            // % n handles the circular check (last with first)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }

            // More than one drop → not rotated sorted
            if (count > 1) {
                return false;
            }}
                  return true;
    

    }
};