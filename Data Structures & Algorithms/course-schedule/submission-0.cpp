class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0) pq.push(i);
        }
        while(!pq.empty()){
            int node=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0) pq.push(it);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inorder[i]!=0) return false;
        }
        return true;
    }
};
