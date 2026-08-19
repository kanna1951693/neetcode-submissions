class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for(int n : nums){
            freqs[n] ++;
        }
        vector<pair<int, int>> f2;
        for(auto &[i, v] : freqs) f2.push_back({v, i});

        sort(f2.begin(), f2.end());

        vector<int> res;
        for(int i=0; i<k; i++) res.push_back(f2[f2.size()-1-i].second);
        return res;

    }
};
