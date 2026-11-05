class Solution {
public:
    int f(int target,vector<int>& nums,vector<int>& dp){
        int way=0;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        for(int i=0;i<nums.size();i++){
          if(nums[i]<=target)
            way+=f(target-nums[i],nums,dp);
        }
        return dp[target]=way;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,-1);
        return f(target,nums,dp);
    }
};