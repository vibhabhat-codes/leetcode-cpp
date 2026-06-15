class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(int num : st)
        {
            if(st.find(num - 1) == st.end())
            {
                int count = 1;
                int current = num;

                while(st.find(current + 1) != st.end())
                {
                    current++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};