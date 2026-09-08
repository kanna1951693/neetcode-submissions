class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, 
                   vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            cur.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(0, target, candidates, cur, res);
        return res;
    }
};