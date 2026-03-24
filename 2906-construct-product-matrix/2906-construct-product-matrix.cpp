class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        const int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;

        vector<long long> arr(size);
        
        // flatten matrix
        int k = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr[k++] = grid[i][j] % MOD;

        // prefix product
        vector<long long> prefix(size,1), suffix(size,1);

        for(int i=1;i<size;i++)
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;

        // suffix product
        for(int i=size-2;i>=0;i--)
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;

        // build answer
        vector<vector<int>> ans(n, vector<int>(m));
        k = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = (prefix[k] * suffix[k]) % MOD;
                k++;
            }
        }

        return ans;
    }
};