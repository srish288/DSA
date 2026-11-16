class Solution {
public:
    //  int f(int ind,int prev,vector<int>& nums, vector<vector<int>> &dp){
    //     if(ind==nums.size()) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int len=0+f(ind+1,prev,nums,dp);
    //     if(prev==-1 || nums[ind]%nums[prev]==0||nums[prev]%nums[ind]==0){
    //         len=max(len,1+f(ind+1,ind,nums,dp));
    //     }
    //     return dp[ind][prev+1]=len;
    //  }
    
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return {};

    sort(nums.begin(), nums.end());

    int maxi = 0;
    int lastind = 0;

    vector<int> dp(n, 1), hash(n);

    for(int i = 0; i < n; i++) {
        hash[i] = i;

        for(int prev = 0; prev < i; prev++) {
            if(nums[i] % nums[prev] == 0 &&
               dp[i] < 1 + dp[prev]) {

                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if(dp[i] > maxi) {
            maxi = dp[i];
            lastind = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastind]);

    while(hash[lastind] != lastind) {
        lastind = hash[lastind];
        temp.push_back(nums[lastind]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

};