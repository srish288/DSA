class Solution {
public:

     bool possible(vector<int>& nums,int limit,int k){
        int curr=0;
        int s=1;
        for(int c:nums){
            if(curr+c<=limit){
                curr+=c;
            }
            else{
            curr=c;
            s+=1;
        }
        }
        return s<=k;
     }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int c:nums){
            high+=c;
        }
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,k)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};