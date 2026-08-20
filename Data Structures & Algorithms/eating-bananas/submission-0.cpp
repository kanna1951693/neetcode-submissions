class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        //low and high represents the k
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (mid == 0) { low = 1; continue; }
            long long total_hours = 0;
            for(int pile : piles) {
                total_hours += (pile + mid - 1LL) / mid;
            }
            if(total_hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
