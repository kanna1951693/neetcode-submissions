class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0,0,nums,target,cur,res);
        return res;
    }

    void dfs(int ind,int sum,vector<int>& nums,int target,vector<int>&cur,vector<vector<int>>& res){        if(sum>target) return;
        if(sum==target){res.push_back(cur);return;}
        if(ind==nums.size()) return;
        //take 
        cur.push_back(nums[ind]);
        dfs(ind,sum+nums[ind],nums,target,cur,res);
        cur.pop_back();
        dfs(ind+1,sum,nums,target,cur,res);
    }
};
