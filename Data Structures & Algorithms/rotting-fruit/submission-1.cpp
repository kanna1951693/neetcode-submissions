class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> pq;
        int freshCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == 2) {
                    pq.push({0, {i, j}});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        if (freshCount == 0) return 0;
        int tim=0;
        vector<int> p={-1,0,1,0};
        vector<int> q={0,-1,0,1};
        while(!pq.empty()){
            int dist=pq.front().first;
            tim=max(tim,dist);
            int r=pq.front().second.first;
            int c=pq.front().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int rr=r+p[i];
                int cc=c+q[i];
                if(rr<0||rr>=n||cc<0||cc>=m||grid[rr][cc]!=1) continue;
                grid[rr][cc]=2;
                freshCount--;
                pq.push({dist+1,{rr,cc}});
            }
        }
        return freshCount==0?tim:-1;
    }
};
