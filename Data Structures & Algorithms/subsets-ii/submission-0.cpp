class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        dfs(0,nums,cur,res);
        return res;
    }

    void dfs(int ind,vector<int>& nums,vector<int>& cur,vector<vector<int>>& res){
        if(ind==nums.size()){ res.push_back(cur);return;} 
        cur.push_back(nums[ind]);
        dfs(ind+1,nums,cur,res);
        cur.pop_back();

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        
        dfs(ind+1,nums,cur,res);
    }
};
