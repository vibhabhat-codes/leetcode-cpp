class Solution {
public:
    int minJumps(vector<int>& arr) {
           int n = arr.size();

        // If already at last index
        if(n == 1) {
            return 0;
        }

        // Map value -> list of indices
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // BFS queue
        queue<int> q;

        // Visited array
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int index = q.front();
                q.pop();

                // Reached last index
                if(index == n - 1) {
                    return steps;
                }

                // Move to index - 1
                if(index - 1 >= 0 && !visited[index - 1]) {
                    visited[index - 1] = true;
                    q.push(index - 1);
                }

                // Move to index + 1
                if(index + 1 < n && !visited[index + 1]) {
                    visited[index + 1] = true;
                    q.push(index + 1);
                }

                // Move to all same value indices
                for(int next : mp[arr[index]]) {

                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                // Important optimization
                mp[arr[index]].clear();
            }

            steps++;
        }

        return -1;
    }
};