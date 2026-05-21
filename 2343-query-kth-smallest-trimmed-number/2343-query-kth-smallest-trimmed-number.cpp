class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

        vector<int> ans;

        // Traverse each query
        for(int i = 0; i < queries.size(); i++) {

            int k = queries[i][0];
            int trim = queries[i][1];

            vector<pair<string,int>> temp;

            // Trim all strings
            for(int j = 0; j < nums.size(); j++) {

                string s = nums[j];

                string trimmed = s.substr(s.length() - trim);

                temp.push_back({trimmed, j});
            }

            // Sort trimmed strings
            sort(temp.begin(), temp.end());

            // kth smallest index
            ans.push_back(temp[k - 1].second);
        }

        return ans;
    }
};