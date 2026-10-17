class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //yaha bhi we will apply multisource bfs
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,-1)); 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [a,b]=q.front();
            
            q.pop();
            for(int d=0;d<4;d++){
                int nr=a+dr[d];
                int nc=b+dc[d];
                if(nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[a][b]+1;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};