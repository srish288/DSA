class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
     //   q.push({0,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0|| i==n-1||j==m-1){
                  if(grid[i][j]==1){
                    q.push({i,j});// multisource bfs
                    vis[i][j]=1;
                }
              }
            }
        }
        //bfs algo
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(grid[nr][nc]==1 && vis[nr][nc]==0){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};