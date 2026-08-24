#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,p;
    cin>>n;
    cin>>p;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int defeated=0;
    for(int i=0;i<n;i++){
        if(p>=h[i]){
            defeated++;
            p-=h[i];
        }
        else{
            p+=h[i];
        }

    }
    cout<<defeated;
    return 0;
}