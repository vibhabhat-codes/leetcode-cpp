class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> last(256, -1);   // stores last index of each character
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // if character already seen inside window
            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }

            last[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};