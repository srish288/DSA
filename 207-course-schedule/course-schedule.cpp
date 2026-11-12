
class Solution {
public:
    bool dfs(int n, vector<vector<int>>& adj,
         vector<int>& vis, vector<int>& pvis) {
        vis[n] = 1;
        pvis[n] = 1;

        for (auto it : adj[n]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pvis)) {
                    return true;
                }
            }
            else if (pvis[it]) {
                return true;
            }
        }

        pvis[n] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

       vector<int> vis(numCourses, 0);
vector<int> pvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pvis)) {
                    return false;
                }
            }
        }

        return true;
    }
};
