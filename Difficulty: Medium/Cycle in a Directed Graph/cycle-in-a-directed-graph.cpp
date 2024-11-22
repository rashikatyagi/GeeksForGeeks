//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // bool dfsCycleDetect(int node, vector<vector<int>> &adj, vector<bool> &visited){
    //     visited[node] = 1;
    //     for(auto it : adj[node]){
    //         if(visited[it] == 0){
    //             if(dfsCycleDetect(it, adj, visited)) return true;
    //         }
    //         else return true;
    //     }
    //     visited[node] = 0;
    //     return false;
    // }
    void bfs(vector<vector<int>>& adj, vector<int> &ans){
        int v = adj.size();
        vector<int> indegree(v, 0);
        //get the indegrees of all the vertices
        for(int i = 0 ; i < v ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                indegree[adj[i][j]]++;
            }
        }
        //push all the vertices with 0 indegree into the queue
        queue<int> q;
        for(int i = 0 ; i < v ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        // vector<bool> visited(V, 0);
        // for(int i = 0 ; i < V ; i++){
        //     for(int j = 0 ; j < adj[i].size() ; j++){
        //         if(visited[adj[i][j]] == 0){
        //             if(dfsCycleDetect(adj[i][j], adj, visited)) return true;
        //         }
        //     }
        // }
        // return false;
        vector<int> ans;
        bfs(adj, ans);
        return V != ans.size();
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends