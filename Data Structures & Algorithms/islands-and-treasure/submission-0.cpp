class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    q.push({i,j});
                }
            }
        }
        vector<int> rr={-1,0,1,0};
        vector<int> cc={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int rc=rr[i]+r;
                int cr=cc[i]+c;
                if(rc<0 || rc>=n ||cr<0 ||cr>=m || grid[rc][cr] != 2147483647) continue;
                grid[rc][cr]=grid[r][c]+1;
                q.push({rc,cr});
            }

        }
    }
};
