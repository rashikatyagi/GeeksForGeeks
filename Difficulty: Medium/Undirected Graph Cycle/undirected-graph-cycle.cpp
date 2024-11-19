//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool bfsCycleDetect(int node, vector<vector<int>>& adj, unordered_map<int, int> &parent, vector<bool> &visited){
    //     queue<int> q;
    //     visited[node] = 1;
    //     q.push(node);
    //     parent[node] = -1;
    //     while(!q.empty()) {
    //         int currnode = q.front();
    //         q.pop();
    //         for(auto it : adj[currnode]){
    //             if(visited[it] == 0){
    //                 q.push(it);
    //                 visited[it] = 1;
    //                 parent[it] = currnode;
    //             }
    //             else if(parent[currnode] != it){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    bool dfsCycleDetect(int node, int parent, vector<vector<int>>& adj, vector<bool> &visited){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(visited[it] == 0){
                bool ans = dfsCycleDetect(it, node, adj, visited);
                if(ans) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool> visited(v, 0);
        // unordered_map<int, int> parent;
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                if(visited[adj[i][j]] == 0){
                    bool ans = dfsCycleDetect(adj[i][j], -1, adj, visited);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends