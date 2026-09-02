bool possible(vector<int>& stalls, int dist, int cows){
    int count=1;
    int last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            count++;
            last=stalls[i];
        }
    }
    return count>=cows;  
}
int aggressiveCows(vector<int>& stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls.back()-stalls.front();
    int ans=0;
    while(low<=high){
        int mid=low + (high - low) / 2;
        if(possible(stalls,mid,cows)){ //TTTTFFFFF
             low=mid+1;
             ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}