class Solution {
public:
    int set(int n){
        int c=0;
        while(n!=0){
            n=n&(n-1);
            c++;
        }
        return c;
    }
    int calculateScore(int a, int b) {
        int c1=0, c2=0;
        c1=set(a);
        c2=set(b);
        if(c1>=c2){
            return c1*c2;
        }
        else{
            return c2/c1;
        }
    }
};