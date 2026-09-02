#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    if(n==1){
      cout<<arr[0]<<"\n";

    }
    else{
      cout<<__gcd(arr[0],arr[n-1])<<"\n";
    }
   }
   
   
    
    return 0;
}