//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    // int solveRE(int w, vector<int>& weight, vector<int>& val){
    //     if(index == weight.size() - 1){
    //         if(weight[index] <= w) return val[index];
    //         return 0;
    //     }
    //     int inclusion = 0;
    //     if(w >= weight[index]){
    //         inclusion = val[index] + solveRE(w - weight[index], weight, val, index + 1);
    //     }
    //     int exclusion = solveRE(w, weight, val, index + 1);
    //     return max(inclusion, exclusion);
    // }
    
    // int solveMem(int w, vector<int>& weight, vector<int>& val, int index, vector<vector<int> > &dp){
    //     if(index == (weight.size() - 1)){
    //         if(weight[index] <= w) return val[index];
    //         return 0;
    //     }
        
    //     if(dp[w][index] != -1) return dp[w][index];
        
    //     int inclusion = 0;
    //     if(w >= weight[index]){
    //         inclusion = val[index] + solveMem(w - weight[index], weight, val, index + 1, dp);
    //     }
    //     int exclusion = solveMem(w, weight, val, index + 1, dp);
    //     dp[w][index] = max(inclusion, exclusion);
    //     return dp[w][index];
    // }
    int solveTab(int w, vector<int>& wt, vector<int>& val){
        //create a dp array
        int n = wt.size();
        vector<vector<int> > dp(w + 1, vector<int>(n + 1, 0));
        //traversing over all rows from back (because the base case is stored at right)
        for(int i = 1 ; i <= w ; i++){
            for(int j = n - 1 ; j >= 0 ; j--){
                int inclusion = 0;
                if(i >= wt[j]){
                    inclusion = val[j] + dp[i - wt[j]][j + 1];
                }
                int exclusion = dp[i][j + 1];
                dp[i][j] = max(inclusion, exclusion);
            }
        }
        return dp[w][0];
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        return solveTab(W, wt, val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends