//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0]; // Sort based on the first element of each subvector
}

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        
      if(arr.size()==1) return arr;  
      sort(arr.begin(), arr.end(), compare);
       
        int mini = arr[0][0];
        int maxi = arr[0][1];
     
      vector< vector<int>> ans;
       bool flag;
        for(int i = 1 ; i < arr.size();i++){
            int f = arr[i][0];
            int s = arr[i][1];
             flag =0;
             
            if(maxi >= f) maxi=max(maxi,s);
            else {
                flag=1;
                ans.push_back({mini,maxi});
                mini = f;
                maxi = s;
                if(i+1==arr.size()) ans.push_back({mini,maxi});
            }
        }
        if(flag==0)  ans.push_back({mini,maxi});
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends