//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size(), m = b.size();
        if(k > (n + m)) return 0;
        int i = 0, j = 0;
        while(i < n && j < m && --k > 0){
            if(a[i] < b[j]) i++;
            else j++;
        }
        while(i < n && --k > 0) i++;
        while(j < m && --k > 0) j++;
        
        if(i == n) return b[j];
        else if(j == m) return a[i];
        return min(a[i], b[j]);
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends