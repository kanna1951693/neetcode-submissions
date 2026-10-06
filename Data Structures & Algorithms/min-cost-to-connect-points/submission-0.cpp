class DSU
{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }

    int ultparent(int x){
        if(parent[x]==x) return x;
        return parent[x]=ultparent(parent[x]);
    }

    bool unionset(int u,int v){
        int ult_u=ultparent(u);
        int ult_v=ultparent(v);
        if(ult_u==ult_v) return false;
        if(size[ult_u]<size[ult_v]){
            swap(ult_u,ult_v);
        }
        size[ult_u]+=size[ult_v];
            parent[ult_v]=ult_u;
            return true;
    }

};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);
        vector<array<int,3>> edges;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int res = 0;

        for (auto& [dist, u, v] : edges) {
            if (dsu.unionset(u, v)) {
                res += dist;
            }
        }
        return res;
    }
};

