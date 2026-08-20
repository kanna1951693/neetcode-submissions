class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int res=0;
        int maxf=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while(((r-l+1)-maxf)>k){
                mpp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
