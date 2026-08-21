class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[r][c]=1;
        vector<int> rc={-1,0,1,0};
        vector<int> cc={0,-1,0,1};
        for(int i=0;i<4;i++){
            int row=r+rc[i];
            int col=c+cc[i];
            if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() 
            || grid[row][col]=='0' || vis[row][col]==1){continue;}

            dfs(row,col,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]!=1){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
