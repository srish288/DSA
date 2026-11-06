
class Solution {
public:

    int f(int i, int j, vector<vector<char>>& matrix,
          vector<vector<int>>& dp) {

        if(i < 0 || j < 0) return 0;

        if(matrix[i][j] == '0') return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, matrix, dp);
        int left = f(i, j-1, matrix, dp);
        int diagonal = f(i-1, j-1, matrix, dp);

        return dp[i][j] = 1 + min({up, left, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                maxi = max(maxi, f(i, j, matrix, dp));

            }
        }

        return maxi * maxi;
    }
};
