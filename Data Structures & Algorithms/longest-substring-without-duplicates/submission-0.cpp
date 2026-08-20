class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int i=0,j=0;
        int n=s.size();
        int maxi=0;
        int cnt=0;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                while(mpp.find(s[j])!=mpp.end()){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0)mpp.erase(s[i]);
                    i++;
                    cnt--;
                }
            }
            else {
                mpp[s[j]]++;
                j++;
                cnt++;
            }
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
};
