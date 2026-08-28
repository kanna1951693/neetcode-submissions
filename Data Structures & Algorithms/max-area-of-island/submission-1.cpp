class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,-1));
        int maxii=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,maxi);
                }
                maxii=max(maxi,maxii);
                maxi=0;
            }
        }
        return maxii;
    }

    void dfs(int r,int c,vector<vector<int>>& grid,int& maxi){
        int n=grid.size();
        int m=grid[0].size();
        maxi++;
        grid[r][c]=0;
        vector<int> rc={-1,0,1,0};
        vector<int> cc={0,-1,0,1};
        for(int i=0;i<4;i++){
            int row=r+rc[i];
            int col=c+cc[i];
            if(row<0 || row>=n ||col<0 ||col>=m ||grid[row][col]==0) continue;
            dfs(row,col,grid,maxi);
        }
    }
};
