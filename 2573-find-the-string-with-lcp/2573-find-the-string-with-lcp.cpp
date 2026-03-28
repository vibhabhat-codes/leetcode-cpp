class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '?');

        char c = 'a';

        // Step 1: Build smallest string
        for (int i = 0; i < n; i++) {
            if (word[i] == '?') {
                if (c > 'z') return "";
                
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = c;
                    }
                }
                c++;
            }
        }

        // Step 2: Validate matrix
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int expected;

                if (word[i] == word[j]) {
                    if (i == n-1 || j == n-1)
                        expected = 1;
                    else
                        expected = 1 + lcp[i+1][j+1];
                } else {
                    expected = 0;
                }

                if (lcp[i][j] != expected)
                    return "";
            }
        }

        return word;
    }
};