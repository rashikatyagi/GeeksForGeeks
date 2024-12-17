//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int maxdist = stalls[n - 1] - stalls[0];
        int start = 1, end = maxdist;
        int ans = 0;
        int mid = start + (end - start) / 2;
        while(start <= end){
            
            int countcow = 1, prev = stalls[0];
            for(int i = 1 ; i < stalls.size() ; i++){
                if(stalls[i] - prev >= mid){
                    countcow++;
                    prev = stalls[i];
                }
            }
            if(countcow >= k){
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends