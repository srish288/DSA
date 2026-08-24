#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b;
    cin>>a>>b;
    int flag=0;
    if(a+b==9){
        flag=1;
    }
    if(a-b==9){
        flag=1;
    }    
    if(a*b==9){
        flag=1;
    }
    if(a/b==9){
        flag=1;
    }
    if(flag==1){
        cout<<"Nine";
    }
    else{
        cout<<"Nein";
    }
   
    
    return 0;
}