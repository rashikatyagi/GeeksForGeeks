//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dpSolutionTopDown(int n, int x, int y, int z, vector<int> &dp){
        //base case
        if(n == 0) return 0;
        //if we return 0 in both cases, then even if we can cut the segment with a particular length, the answer will be 1 only
        if(n < 0) return INT_MIN;
        
        if(dp[n] != INT_MIN){
            return dp[n];
        }
        
        // recursive calls
        int ans1 = 1 + dpSolutionTopDown(n - x, x, y, z, dp);
        int ans2 = 1 + dpSolutionTopDown(n - y, x, y, z, dp);
        int ans3 = 1 + dpSolutionTopDown(n - z, x, y, z, dp);
        
        dp[n] = max(max(ans1, ans2), ans3);
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, INT_MIN);
        int ans = dpSolutionTopDown(n, x, y, z, dp);
        if(ans < 0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends