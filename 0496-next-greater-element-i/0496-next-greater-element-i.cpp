class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,
                                   vector<int>& nums2) {

        stack<int> st;

        unordered_map<int, int> nextGreater;

        // Find next greater element for nums2
        for (int num : nums2) {

            while (!st.empty() && num > st.top()) {

                nextGreater[st.top()] = num;

                st.pop();
            }

            st.push(num);
        }

        // Elements still in stack have no next greater
        while (!st.empty()) {

            nextGreater[st.top()] = -1;

            st.pop();
        }

        // Build answer for nums1
        vector<int> ans;

        for (int num : nums1) {

            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};