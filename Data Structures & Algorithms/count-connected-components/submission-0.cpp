 class Dsu{
    public:
    vector<int> size;
    vector<int> parent;

    Dsu(int n){
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int ult_parent(int node){
        if(parent[node]==node)return node;
        return parent[node]=ult_parent(parent[node]);
    }
    bool bysize(int x, int y) {
    int ult_x = ult_parent(x);
    int ult_y = ult_parent(y);

    if (ult_x == ult_y) return false;

    if (size[ult_x] > size[ult_y]) {
        size[ult_x] += size[ult_y];
        parent[ult_y] = ult_x;
    } else {
        size[ult_y] += size[ult_x];
        parent[ult_x] = ult_y;
    }

    return true; 
}
 };
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Dsu dsu(n);
        int res=n;
        for(auto& it:edges){
            if(dsu.bysize(it[0],it[1])){
                res--;
            }
        }
        return res;
    }
};
