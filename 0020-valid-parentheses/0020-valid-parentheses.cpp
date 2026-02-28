class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // If opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // If stack empty, no matching open bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching pair
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};