class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        recursion(0, nums, cur, res);
        return res;
    }

    void recursion(int node, const vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if (node == nums.size()) {
            res.push_back(cur);
            return;
        }

        // Include nums[node]
        cur.push_back(nums[node]);
        recursion(node + 1, nums, cur, res);

        // Backtrack (exclude nums[node])
        cur.pop_back();
        recursion(node + 1, nums, cur, res);
    }
};