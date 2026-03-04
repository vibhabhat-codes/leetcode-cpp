class Solution {
public:
    int longestPalindrome(string s) {

        vector<int> count(128, 0);

        for(char c : s)
            count[c]++;

        int length = 0;
        bool oddFound = false;

        for(int c : count) {
            if(c % 2 == 0)
                length += c;
            else {
                length += c - 1;
                oddFound = true;
            }
        }

        if(oddFound)
            length += 1;

        return length;
    }
};