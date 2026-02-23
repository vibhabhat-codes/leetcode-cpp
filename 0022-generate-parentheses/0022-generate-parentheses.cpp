class Solution {
public:
    vector<string> ans;

    void solve(string curr, int open, int close, int n) {

        // If full length reached
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if possible
        if (open < n) {
            solve(curr + "(", open + 1, close, n);
        }

        // Add ')' if valid
        if (close < open) {
            solve(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};