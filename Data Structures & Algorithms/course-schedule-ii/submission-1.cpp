class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> inorder(numCourses,0);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }
        queue<int> pq;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){pq.push(i); ans.push_back(i); } 

        }
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0){pq.push(it); ans.push_back(it); } 
            }
        }
        return ans.size()==numCourses?ans:vector<int>{};
    }
};
