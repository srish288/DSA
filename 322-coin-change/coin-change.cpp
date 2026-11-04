class Solution {
public:
    int f(int idx,vector<int>& coins, int amount,vector<vector<int>>& dp){
            if(idx==0){
                if(amount%coins[idx]==0){
                    return amount/coins[idx];
                }
                else{
                    return 1e9;
                }
            }
            if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notake=0+f(idx-1,coins,amount,dp);
        int take=INT_MAX;
        if(coins[idx]<=amount)
          take=1+f(idx,coins,amount-coins[idx],dp);
      
        return dp[idx][amount]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        ans= f(n-1,coins,amount,dp);
        if(ans>=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};