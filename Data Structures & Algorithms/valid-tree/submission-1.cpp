class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        vector<bool> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(!dfs(0,-1,vis,adj)) return false;
        for(auto it:vis){
            if(it==0) return false;
        }
        return true;
    }

    bool dfs(int node,int parent,vector<bool>& vis,vector<vector<int>>& adj){
        if(vis[node]==1) return false;
        vis[node]=1;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!dfs(it,node,vis,adj)) return false;
        }
        return true;
    }
};
