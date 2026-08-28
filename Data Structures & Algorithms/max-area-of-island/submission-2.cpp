class Solution {
public:
     vector<int> rc={-1,0,1,0};
    vector<int> cc={0,-1,0,1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,-1));
        int maxii=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,n,m,grid,maxi);
                }
                maxii=max(maxi,maxii);
                maxi=0;
            }
        }
        return maxii;
    }

    void dfs(int r,int c,int n,int m,vector<vector<int>>& grid,int& maxi){
        maxi++;
        grid[r][c]=0;
       
        for(int i=0;i<4;i++){
            int row=r+rc[i];
            int col=c+cc[i];
            if(row<0 || row>=n ||col<0 ||col>=m ||grid[row][col]==0) continue;
            dfs(row,col,n,m,grid,maxi);
        }
    }
};
