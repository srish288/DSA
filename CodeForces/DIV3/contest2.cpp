#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
   vector<long long> arr(n);
    for(int i=0;i<n;i++){
          cin>>arr[i];
    }
    int ev2=0,ev1=0,odd=0;
    unordered_map<long long,int> f;
    for(long long a:arr){
        f[a]++;   
    }
    int freq=0;
    for(auto a:f){
        freq=max(freq,a.second);
    }
    for(long long a:arr){
        if(a%2==1){
            odd++;
        }
        else{ 
            if(a%4==0) ev1++;
             else ev2++;
        }
    }
    freq=max(freq,odd);
    freq=max(freq,ev1);
    freq=max(freq,ev2);

    cout<<freq<<"\n";
   }
   
    return 0;
}