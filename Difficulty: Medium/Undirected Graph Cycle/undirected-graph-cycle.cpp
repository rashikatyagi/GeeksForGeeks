//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int source, int parent, vector<int> adj[], vector<bool> &visited) {
        //mark the souce in visited
        visited[source] = 1;
        
        //check the adj list for adjacent nodes
        for(auto it : adj[source]){
            if(it == parent) continue;
            else if(visited[it] == 0){
                bool ans = dfs(it, source, adj, visited);
                if(ans) return true;
            }
            else return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i = 0 ; i < V ; i++){
            if(visited[i] == 0){
                bool ans = dfs(i, -1, adj, visited);
                if(ans) return true;
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
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends