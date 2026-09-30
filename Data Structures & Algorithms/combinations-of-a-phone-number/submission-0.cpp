class Solution {
public:
    vector<string> letterCombinations(string digits) {
           vector<string> res;
        if (digits.empty()) return res;
     
        vector<vector<char>> num={
            { },{'a','b','c'},{'d','e','f'},
            {'g','h','i'},{'j','k','l'},{'m','n','o'},
            {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
        };
        string s="";
        dfs(0,digits,s,res,num);
        return res;
    }

    void dfs(int ind,string& digits,string& s,vector<string>& res,vector<vector<char>>& num){
        if(ind==digits.size()){
            res.push_back(s);
            return;
        }
        int x=digits[ind]-'1';
        for(int i=0;i<num[x].size();i++){
            s.push_back(num[x][i]);
            dfs(ind+1,digits,s,res,num);
            s.pop_back();
        }

    }
};
