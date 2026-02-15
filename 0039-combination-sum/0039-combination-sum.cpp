class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target) {
        // Base case
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);

            // i (not i+1) because we can reuse same number
            solve(i, candidates, target - candidates[i]);

            // backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};