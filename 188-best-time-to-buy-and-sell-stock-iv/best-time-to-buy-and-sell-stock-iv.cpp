class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>& p,vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==p.size()) return 0;
        if( dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            dp[ind][buy][cap]=max(-p[ind]+f(ind+1,0,cap,p,dp),f(ind+1,1,cap,p,dp));
        }
        else{
            dp[ind][buy][cap]=max(p[ind]+f(ind+1,1,cap-1,p,dp),f(ind+1,0,cap,p,dp));
        
        }
        return dp[ind][buy][cap];
    }  
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,-1)));
       return f(0,1,k,prices,dp);
        
    }
};