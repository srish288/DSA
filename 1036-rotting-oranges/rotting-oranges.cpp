
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Store all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh oranges present
        if (fresh == 0) {
            return 0;
        }

        // Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int minutes = 0;

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int size = q.size();
            bool rottenThisMinute = false;

            // Process all oranges rotting at the current level
            for (int i = 0; i < size; i++) {
                pair<int, int> current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;

                // Check all four adjacent cells
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Check boundaries and fresh orange
                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }

            // Increase time only if new oranges became rotten
            if (rottenThisMinute) {
                minutes++;
            }
        }

        // Step 3: Check if any fresh orange remains
        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
