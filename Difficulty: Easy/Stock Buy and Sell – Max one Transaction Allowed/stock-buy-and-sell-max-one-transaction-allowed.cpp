//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int max_profit = 0;
        vector<int> maximums(n, 0);
        int maxi = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            maximums[i] = max(maxi, prices[i]);
            maxi = maximums[i];
        }
        for(int i = 0 ; i < n ; i++){
            max_profit = max(max_profit, maximums[i] - prices[i]);
        }
        return max_profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends