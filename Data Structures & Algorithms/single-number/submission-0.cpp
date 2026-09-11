class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt=nums[0];
        for(int i=1;i<nums.size();i++){
            cnt=cnt^nums[i];
        }
        return cnt;
    }
};
