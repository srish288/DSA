class Solution {
  public:
  
    string multiplyStrings(string &s1, string &s2) {
        // code here
        
        bool neg = false;

            if (s1[0] == '-') {
                   neg = !neg;
                   s1 = s1.substr(1);
                }

                if (s2[0] == '-') {
                    neg = !neg;
                    s2 = s2.substr(1);
                }
                int p1 = 0;
                while (p1 < s1.size() - 1 && s1[p1] == '0')
                    p1++;

                int p2 = 0;
                while (p2 < s2.size() - 1 && s2[p2] == '0')
                    p2++;
       s1=s1.substr(p1);
       s2=s2.substr(p2);
      if(s1=="0" || s2=="0"){
          return "0";
      }
      int n=s1.size();
      int m=s2.size();
       vector<int> res(n+m,0);
       for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=0;j--){
               int a=s1[i]-'0';
               int b=s2[j]-'0';
               int pro=a*b;
               int pos1=i+j+1;
               int pos2=i+j;
               int sum=pro+res[pos1];
               res[pos1]=sum%10;
               res[pos2]+=sum/10;
           }
       }
       string ans="";
       int i=0;
       while(i<res.size() && res[i]==0){
           i++;
       }
       while(i<res.size()){
           ans+=char(res[i]+'0');
           i++;
       }
       if (neg)
          ans = "-" + ans;

       return ans;
    }
};
