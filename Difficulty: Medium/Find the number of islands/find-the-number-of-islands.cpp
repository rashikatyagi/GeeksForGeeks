//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            //up
            if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1' && visited[currRow - 1][currCol] == 0){
                visited[currRow - 1][currCol] = 1;
                q.push({currRow - 1, currCol});
            }
            //down
            if(currRow + 1 < n && grid[currRow + 1][currCol] == '1' && visited[currRow + 1][currCol] == 0){
                visited[currRow + 1][currCol] = 1;
                q.push({currRow + 1, currCol});
            }
            //left
            if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1' && visited[currRow][currCol - 1] == 0){
                visited[currRow][currCol - 1] = 1;
                q.push({currRow, currCol - 1});
            }
            //right
            if(currCol + 1 < m && grid[currRow][currCol + 1] == '1' && visited[currRow][currCol + 1] == 0){
                visited[currRow][currCol + 1] = 1;
                q.push({currRow, currCol + 1});
            }
            // diagonal up left
            if(currRow - 1 >= 0 && currCol - 1 >= 0 && grid[currRow - 1][currCol - 1] == '1' && visited[currRow - 1][currCol - 1] == 0){
                visited[currRow - 1][currCol - 1] = 1;
                q.push({currRow - 1, currCol - 1});
            }
            // diagonal down left
            if(currRow + 1 < n && currCol - 1 >= 0 && grid[currRow + 1][currCol - 1] == '1' && visited[currRow + 1][currCol - 1] == 0){
                visited[currRow + 1][currCol - 1] = 1;
                q.push({currRow + 1, currCol - 1});
            }
            // diagonal up right
            if(currCol + 1 < m && currRow - 1 >= 0 && grid[currRow - 1][currCol + 1] == '1' && visited[currRow - 1][currCol + 1] == 0){
                visited[currRow - 1][currCol + 1] = 1;
                q.push({currRow - 1, currCol + 1});
            }
            // diagonal down right
            if(currCol + 1 < m && currRow + 1 < n && grid[currRow + 1][currCol + 1] == '1' && visited[currRow + 1][currCol + 1] == 0){
                visited[currRow + 1][currCol + 1] = 1;
                q.push({currRow + 1, currCol + 1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        int number = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1' && visited[row][col] == 0){
                    bfs(row, col, grid, visited);
                    number++;
                }
            }
        }
        return number;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends