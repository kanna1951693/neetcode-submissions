class Dsu{
    public:
    vector<int> parent,size;
    Dsu(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int ult(int node){
        if(parent[node]==node) return node;
        return parent[node]=ult(parent[node]);
    }

    bool unite(int x,int y){
        int ult_x=ult(x);
        int ult_y=ult(y);
        if(ult_x==ult_y) return false;

        if(size[x]>size[y]){
            parent[ult_y]=ult_x;
            size[ult_x]+=size[ult_y];
        }
        else {
            parent[ult_x]=ult_y;
            size[ult_y]+=size[ult_x];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Dsu dsu(n);
        for(auto& edge:edges){
            if(!dsu.unite(edge[0],edge[1])){
                return edge;
            }
        }
        return {};
    }
};

