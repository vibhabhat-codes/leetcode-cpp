class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;     
    unordered_set<int> resultSet;
    for (int x : nums1) {
        set1.insert(x);
    }
    for(int y: nums2){
        if(set1.find(y)!=set1.end()){
            resultSet.insert(y);
        }}
         vector<int> result(resultSet.begin(), resultSet.end());
    return result;

    }

    
};