class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            int j1 = i;
            while(j1 < n && days[j1] < days[i] + 1) {
                j1++;
            }

            int j7 = i;
            while(j7 < n && days[j7] < days[i] + 7) {
                j7++;
            }

            int j30 = i;
            while(j30 < n && days[j30] < days[i] + 30) {
                j30++;
            }

            int cost1 = costs[0] + dp[j1];
            int cost7 = costs[1] + dp[j7];
            int cost30 = costs[2] + dp[j30];

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};