class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for(int i=0;i<=n;i++){
            int res=0;
            for(int j=0;j<32;j++){
                if((1<<j)&i){
                    res++;
                }
            }
            ret.push_back(res);
        }
        return ret;
    }
};
