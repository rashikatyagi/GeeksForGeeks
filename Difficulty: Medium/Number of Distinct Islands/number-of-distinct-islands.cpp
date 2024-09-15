//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &visited, set<vector<pair<int, int>>> &st){
        queue<pair<int, int>> q;
        visited[row][col] = 1;
        q.push({row, col});
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        vector<pair<int, int>> temp;
        while(!q.empty()){
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            temp.push_back({frontRow - row, frontCol - col});
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int newRow = frontRow + delrow[i];
                int newCol = frontCol + delcol[i];
                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 
                && newCol < grid[0].size() && grid[newRow][newCol] && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
        st.insert(temp);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        set<vector<pair<int, int>>> st;
        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] && !visited[row][col]){
                    bfs(row, col, grid, visited, st);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends