//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    const long long int c = 1000000007;
    long long solveMem(int n, int k, vector<long long int> &dp){
        if(n == 1) return k % c;
        if(n == 2) return (k % c + (k % c) * ((k - 1) % c) % c) % c;
        
        if(dp[n] != -1) return dp[n];
        
        long long int ans = (solveMem(n - 1, k, dp) % c + solveMem(n - 2, k, dp) % c) % c * ((k - 1) % c) % c;
        dp[n] = ans % c;
        return dp[n];
    }
    long long countWays(int n, int k){
        vector<long long int> dp(n + 1, -1);
        return solveMem(n, k, dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends