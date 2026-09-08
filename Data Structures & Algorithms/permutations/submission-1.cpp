class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> pick(nums.size(),false);
        dfs(nums,cur,res,pick);
        return res;
    }

    void dfs(vector<int>&nums,vector<int>&cur,vector<vector<int>>& res,vector<bool>& pick){
        if(cur.size()==nums.size()) {res.push_back(cur);return;}

        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                cur.push_back(nums[i]);
                pick[i]=true;
                dfs(nums,cur,res,pick);
                pick[i]=0;
                cur.pop_back();
            }
        }
    }
};
