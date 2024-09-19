//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int source, vector<int> adj[], vector<int> &visited, vector<int> &path_visited){
        visited[source] = 1;
        path_visited[source] = 1;
        for(auto it : adj[source]){
            if(visited[it] == -1){
                if(dfs(it, adj, visited, path_visited)){
                    return true;
                }
            }
            else if(path_visited[it]){
                return true;
            }
        }
        path_visited[source] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, - 1);
        vector<int> path_visited(V, 0);
        for(int i = 0 ; i < V ; i++){
            if(visited[i] == -1){
                if(dfs(i, adj, visited, path_visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends