class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Initialize with first possible triplet
        int closest = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                
                int sum = nums[i] + nums[l] + nums[r];
                
                // Update closest if this sum is nearer to target
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                    return sum;   // exact match
            }
        }
        
        return closest;
    }
};