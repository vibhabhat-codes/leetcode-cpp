class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        for (char c : t)
            need[c]++;

        int left = 0;
        int missing = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            if (need[s[right]] > 0)
                missing--;

            need[s[right]]--;

            while (missing == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0)
                    missing++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};