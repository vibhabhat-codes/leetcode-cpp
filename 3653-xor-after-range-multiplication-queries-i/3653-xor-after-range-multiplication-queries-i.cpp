class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;

        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];

            for(int idx = l; idx <= r; idx += k){
                nums[idx] = (nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for(int num : nums){
            ans ^= num;
        }

        return ans;
    }
};