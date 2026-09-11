class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sp;
        string s="";
        dfs(n,n,s,sp);
        return sp;
    }
    void dfs(int n,int m,string s,vector<string>& sp){
        if(n==0 && m==0) {sp.push_back(s);return;}
        //open 
        if(n>0){
            s.push_back('(');
            dfs(n-1,m,s,sp);
            s.pop_back();
        }
        if(m>0 && m>n){
            s.push_back(')');
            dfs(n,m-1,s,sp);
            s.pop_back();
        }
    }

};
