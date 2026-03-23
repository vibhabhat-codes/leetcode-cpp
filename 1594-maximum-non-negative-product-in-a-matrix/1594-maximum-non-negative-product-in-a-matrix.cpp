class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long MOD = 1e9 + 7;

        vector<vector<long>> maxDP(m, vector<long>(n));
        vector<vector<long>> minDP(m, vector<long>(n));

        maxDP[0][0] = grid[0][0];
        minDP[0][0] = grid[0][0];

        // first column
        for(int i = 1; i < m; i++) {
            maxDP[i][0] = maxDP[i-1][0] * grid[i][0];
            minDP[i][0] = maxDP[i][0];
        }

        // first row
        for(int j = 1; j < n; j++) {
            maxDP[0][j] = maxDP[0][j-1] * grid[0][j];
            minDP[0][j] = maxDP[0][j];
        }

        // fill rest
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                long val = grid[i][j];

                long a = maxDP[i-1][j] * val;
                long b = minDP[i-1][j] * val;
                long c = maxDP[i][j-1] * val;
                long d = minDP[i][j-1] * val;

                maxDP[i][j] = max({a,b,c,d});
                minDP[i][j] = min({a,b,c,d});
            }
        }

        long ans = maxDP[m-1][n-1];

        if(ans < 0) return -1;

        return ans % MOD;
    }
};