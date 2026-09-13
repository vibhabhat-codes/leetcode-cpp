class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 2) {
                    q.push({r, c});
                }

                if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for (int j = 0; j < 4; j++) {

                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    // Check boundary
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // If fresh, make it rotten
                    if (grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        // If fresh oranges are still left
        if (fresh > 0)
            return -1;

        return max(0, minutes - 1);
    }
};