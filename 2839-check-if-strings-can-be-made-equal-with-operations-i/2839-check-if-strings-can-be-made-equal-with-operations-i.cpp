class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        vector<char> a1 = {s1[0], s1[2]};
        vector<char> a2 = {s2[0], s2[2]};
        
        vector<char> b1 = {s1[1], s1[3]};
        vector<char> b2 = {s2[1], s2[3]};
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        
        return a1 == a2 && b1 == b2;
    }
};