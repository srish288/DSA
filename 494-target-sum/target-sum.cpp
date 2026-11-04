class Solution {
public:
   int f(vector<int> &nums,int tar){
    int n=nums.size();
    vector<int> prev(tar+1,0) , cur(tar+1,0);
    if(nums[0]==0) prev[0]=2;
    else prev[0]=1;
    if(nums[0]!=0 && nums[0]<=tar) prev[nums[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=tar;sum++){
            int ntake=prev[sum];
            int take=0;
            if(nums[i]<=sum) take=prev[sum-nums[i]];
            cur[sum]=ntake+take;
        }
        prev=cur;
    }
    return prev[tar];

   }
   

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums){
            sum+=it;
        }
        if(sum-target<0 || (sum-target)%2) return false;
        return f(nums,(sum-target)/2); 
    }
};