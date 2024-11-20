//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int source, vector<vector<int>>& adj, vector<bool> &visited, stack<int> &st){
        visited[source] = 1;
        for(auto it : adj[source]){
            if(visited[it] == 0){
                dfs(it, adj, visited, st);
            }
        }
        st.push(source);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int v = adj.size();
        vector<bool> visited(v, 0);
        stack<int> st;
        for(int node = 0 ; node < v ; node++){
            if(visited[node] == 0){
                dfs(node, adj, visited, st);
            }
        }
        // remove the elements from the stack
        vector<int> answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends