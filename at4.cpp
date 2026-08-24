#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    string s;
      unordered_map<string,int> f;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>s;

        for(char &ch:s){
            ch=tolower(ch);
        }
        f[s]++;
        count=max(count,f[s]);

    }
    cout<<count;
    
    return 0;
}