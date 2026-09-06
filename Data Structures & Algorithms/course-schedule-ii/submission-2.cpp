class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inorder[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inorder[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        ans.reserve(numCourses); // Pre-allocates memory to prevent dynamic reallocations

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                if (--inorder[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }
};