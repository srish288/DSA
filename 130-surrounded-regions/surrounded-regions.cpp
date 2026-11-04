class Solution {
public:
     void dfs(int r, int c ,vector<vector<char>> & board,int delrow[],int delcol[],vector<vector<char>> & vis){
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1 && board[nr][nc]=='O'){
               dfs(nr,nc,board,delrow,delcol,vis);
            }
        }
     }
    void solve(vector<vector<char>>& board) {
         int n=board.size();
        int m=board[0].size();
        vector<vector<char>>  vis(n,vector<char>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,delrow,delcol,vis);
            }
            //last row
             if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,board,delrow,delcol,vis);
            }

        }
         for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,delrow,delcol,vis);
            }
            //last col
             if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,delrow,delcol,vis);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                 }
            }
        }
    }
};