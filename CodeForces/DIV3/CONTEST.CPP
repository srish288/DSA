#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    int count=0;
    for(int i=0;i<n;i+=k){
          if(a.substr(i,k)==string(k,'1')){
                count++;
          }
    }
    cout<<count<<"\n";
   }
   
    return 0;
}