class Solution {
public:
 int f(int idx,vector<int>& coins, int amount,vector<vector<int>>& dp){
            if(idx==0){
                 return amount%coins[idx]==0;
            }
            if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notake=0+f(idx-1,coins,amount,dp);
        int take=0;
        if(coins[idx]<=amount)
          take=f(idx,coins,amount-coins[idx],dp);
      
        return dp[idx][amount]=(take+notake);
    }
  
    int change(int amount, vector<int>& coins) {
         int ans=0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        ans= f(n-1,coins,amount,dp);
        // if(ans>=1e9){
        //     return 0;
        // }
        // else{
            return ans;
        
    
    }
};

   