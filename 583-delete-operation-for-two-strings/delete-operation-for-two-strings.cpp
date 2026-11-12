class Solution {
public:
   int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                 if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                 }
                 else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
            }
    
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int l=longestCommonSubsequence(word1,word2);
        int a=n-l;
        int b=m-l;
        return a+b;
    }
};