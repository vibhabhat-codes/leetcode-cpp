class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // Min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < nums.size(); i++) {

            // Insert current element
            pq.push(nums[i]);

            // Keep heap size only k
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Top element is kth largest
        return pq.top();
    }
};