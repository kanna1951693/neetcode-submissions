class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int h_l=0,h_r=0;
        int cnt=0;
        while(l<r){
            h_l=max(h_l,height[l]);
            h_r=max(h_r,height[r]);
            if(h_l<=h_r){
                cnt+=(h_l-height[l]);
                l++;
            }
            else{
                cnt+=(h_r-height[r]);
                r--;
            }
            
            
        }
        return cnt;
    }
};
