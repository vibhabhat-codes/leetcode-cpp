class Solution {
public:
    vector<string> ans;

    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(string digits, int index, string current) {

        // Base case
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        solve(digits, 0, "");
        return ans;
    }
};