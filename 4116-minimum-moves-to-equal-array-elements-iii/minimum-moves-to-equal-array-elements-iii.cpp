class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int c=0;
        for(int num:nums){
            c+=abs(maxi-num);
        }
        return c;
    }
};