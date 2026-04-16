class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
       int n = nums.size();
        unordered_map<int, vector<int>> pos_map;
        
        // Group indices by their values
        for (int i = 0; i < n; ++i) {
            pos_map[nums[i]].push_back(i);
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (int q_idx : queries) {
            int val = nums[q_idx];
            const vector<int>& indices = pos_map[val];
            
            // If no other index has the same value
            if (indices.size() <= 1) {
                answer.push_back(-1);
                continue;
            }
            
            // Find the position of q_idx in the sorted indices list
            auto it = lower_bound(indices.begin(), indices.end(), q_idx);
            int pos = distance(indices.begin(), it);
            
            int min_dist = n; // Initialize with max possible circular distance
            int m = indices.size();
            
            // Candidate 1: The element to the immediate left in the list
            // We use (pos - 1 + m) % m to handle circular wrap-around in the index list
            int left_idx = indices[(pos - 1 + m) % m];
            int dist_left = abs(q_idx - left_idx);
            min_dist = min(min_dist, min(dist_left, n - dist_left));
            
            // Candidate 2: The element to the immediate right in the list
            int right_idx = indices[(pos + 1) % m];
            int dist_right = abs(q_idx - right_idx);
            min_dist = min(min_dist, min(dist_right, n - dist_right));
            
            answer.push_back(min_dist);
        }
        
        return answer;
     
    }
};