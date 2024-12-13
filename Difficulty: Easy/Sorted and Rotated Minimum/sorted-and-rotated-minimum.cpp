//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n = arr.size();
        int start = 0, end = n - 1;
        int mid = start + (end - start) / 2;
        
        while(start < end){
            if(mid + 1 < n && arr[mid] > arr[mid + 1]) return arr[mid + 1];
            else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]) return arr[mid];
            else if(arr[mid] > arr[0]) start = mid + 1;
            else end = mid - 1;
            
            mid = start + (end - start) / 2;
        }
        return arr[0];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends