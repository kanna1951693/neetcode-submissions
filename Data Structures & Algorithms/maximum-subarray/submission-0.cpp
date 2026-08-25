class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int sum=0;
        int maxi=nums[0];
        while(j<n){
            sum+=nums[j];
            maxi=max(sum,maxi);
            if(sum<0){sum=0;}
            j++;
        }
        return maxi;
    }
};
