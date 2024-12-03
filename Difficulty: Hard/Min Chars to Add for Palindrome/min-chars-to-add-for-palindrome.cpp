//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
         int n = s.size();
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string concat = s + "#" + rev_s;
    
    int m = concat.size();
    vector<int> lps(m, 0);
    
    for (int i = 1; i < m; i++) {
        int len = lps[i - 1];
        while (len > 0 && concat[i] != concat[len]) {
            len = lps[len - 1];
        }
        if (concat[i] == concat[len]) {
            len++;
        }
        lps[i] = len;
    }
    
    return n - lps[m - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends