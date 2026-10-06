class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(cost.size(),-1);
        return min(cos(n-1,cost,dp),cos(n-2,cost,dp));
    }
    int cos(int ind,vector<int>& cost,vector<int>& dp){
        if(ind==0 || ind==1) return dp[ind]=cost[ind];

        if (dp[ind] != -1) return dp[ind];
        int x=cos(ind-1,cost,dp);
        int y=cos(ind-2,cost,dp);
        return dp[ind]=min(x,y)+cost[ind];
    }

};
