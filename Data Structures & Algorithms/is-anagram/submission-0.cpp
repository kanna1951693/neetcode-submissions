class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        if(s.size()!=t.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        for(auto it:mpp){
            if(it.second!=0) return false;
        }
        return true;
    }
};
