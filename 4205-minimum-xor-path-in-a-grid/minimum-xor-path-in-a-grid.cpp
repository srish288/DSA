class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    bool f(int i, int j, int xr) {
        if (i < 0 || j < 0)
            return false;

        if (i == 0 && j == 0)
            return grid[0][0] == xr;

        if (dp[i][j][xr] != -1)
            return dp[i][j][xr];

        int prev = xr ^ grid[i][j];

        bool up = f(i - 1, j, prev);
        bool left = f(i, j - 1, prev);

        return dp[i][j][xr] = (up || left);
    }

    int minCost(vector<vector<int>>& g) {
        grid = g;

        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(1024, -1)
        ));

        for (int xr = 0; xr < 1024; xr++) {
            if (f(m - 1, n - 1, xr))
                return xr;
        }

        return -1;
    }
};