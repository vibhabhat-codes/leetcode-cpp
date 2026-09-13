class Solution {
public:

    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check if the new cell is inside the grid
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Already visited
            if (visited[nr][nc])
                continue;

            // Reverse water-flow condition
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row
        for (int c = 0; c < n; c++) {
            dfs(0, c, heights, pacific);
        }

        // Pacific: left column
        for (int r = 0; r < m; r++) {
            dfs(r, 0, heights, pacific);
        }

        // Atlantic: bottom row
        for (int c = 0; c < n; c++) {
            dfs(m - 1, c, heights, atlantic);
        }

        // Atlantic: right column
        for (int r = 0; r < m; r++) {
            dfs(r, n - 1, heights, atlantic);
        }

        // Find cells reachable from BOTH oceans
        vector<vector<int>> result;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};