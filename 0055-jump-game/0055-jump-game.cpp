class Solution {
public:
    bool canJump(vector<int>& nums) {

        int farthest = 0;

        for(int i = 0; i < nums.size(); i++) {

            // cannot reach this index
            if(i > farthest) {
                return false;
            }

            // update farthest reachable index
            farthest = max(farthest, i + nums[i]);

            // already can reach last index
            if(farthest >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};