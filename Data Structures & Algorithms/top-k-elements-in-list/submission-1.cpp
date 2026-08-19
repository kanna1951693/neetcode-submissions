class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        vector<int> buk[nums.size()+1];
        for(auto [num,freq]:mpp){
            buk[freq].push_back(num); 
        }
        vector<int> ans;
        for(int i=nums.size();i>=0 && ans.size()<k;i--){
            if(ans.size()==k) break;
            for (int num : buk[i]) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
