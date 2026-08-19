class Solution {
public:
    int maxArea(vector<int>& heights) {
        int h_l=0;
        int h_r=0;
        int l=0;
        int r=heights.size()-1;
        int max_w=0;
        while(l<r){
            h_l=heights[l];
            h_r=heights[r];
            int he=min(h_l,h_r);
            max_w=max(max_w,he*(r-l));
            if(h_l<h_r) l++;
            else r--;
        }
        return max_w;
    }
};
