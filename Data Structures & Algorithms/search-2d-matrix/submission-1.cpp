class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target==matrix[mid][m-1])return true;
            else if(target>matrix[mid][m-1]) low=mid+1;
            else high=mid-1;
        }
        if (low >= n) return false;
        int mid=low;
        low=0;
        high=m-1;
        while(low<=high){
            int midi=low+(high-low)/2;
            if(target==matrix[mid][midi])return true;
            else if(target>matrix[mid][midi]) low=midi+1;
            else high=midi-1;
        }
        return false;
    }
};
