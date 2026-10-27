class Solution {
public:
     void dfs(vector<vector<int>>& image, int r, int c, int color,int initial){
        int n=image[0].size();
        int m=image.size();
        if(r<0 || c<0 || r>=m||c>=n  ){
            return;
        }
        if(image[r][c]!=initial){
            return;
        }
             image[r][c]=color;
         
             dfs(image,r-1,c,color,initial);
             dfs(image,r+1,c,color,initial);
             dfs(image,r,c-1,color,initial);
             dfs(image,r,c+1,color,initial);
     }
  
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial =image[sr][sc];
        if(initial==color){
            return image;
        }
            dfs(image,sr,sc,color,initial);
               
        return image;
    }
};