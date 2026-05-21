class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> prefixes;

        // Store all prefixes from arr1
        for(int i = 0; i < arr1.size(); i++) {

            string s = to_string(arr1[i]);

            string prefix = "";

            for(int j = 0; j < s.length(); j++) {

                prefix += s[j];

                prefixes.insert(prefix);
            }
        }

        int ans = 0;

        // Check prefixes of arr2
        for(int i = 0; i < arr2.size(); i++) {

            string s = to_string(arr2[i]);

            string prefix = "";

            for(int j = 0; j < s.length(); j++) {

                prefix += s[j];

                // Prefix exists in arr1
                if(prefixes.find(prefix) != prefixes.end()) {

                    ans = max(ans, (int)prefix.length());
                }
            }
        }

        return ans;
    }
};