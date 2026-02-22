class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) return "";
        
        // Take first string as reference
        string first = strs[0];
        
        for (int i = 0; i < first.length(); i++) {
            
            char current = first[i];
            
            // Compare with every other string
            for (int j = 1; j < strs.size(); j++) {
                
                // If index exceeds length OR mismatch found
                if (i >= strs[j].length() || strs[j][i] != current) {
                    return first.substr(0, i);
                }
            }
        }
        
        // If fully matched
        return first;
    }
};