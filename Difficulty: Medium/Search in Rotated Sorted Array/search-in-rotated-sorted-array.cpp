//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binarySearch(vector<int> &arr, int target, int start, int end){
        int mid = start + (end - start) / 2;
        while(start <= end){
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) end = mid - 1;
            else start = mid + 1;
            
            mid = start + (end - start) / 2;
        }
        return -1;
    }
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int start = 0, end = n - 1;
        int mid = start + (end - start) / 2;
        int point = -1;
        while(start <= end){
            if(mid + 1 < n && arr[mid] > arr[mid + 1]){
                point = mid;
                break;
            }
            else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1]){
                point = mid - 1;
                break;
            }
            else if(arr[mid] > arr[0]) start = mid + 1;
            else end = mid - 1;
            
            mid = start + (end - start) / 2;
        }
        int ans1 = binarySearch(arr, key, 0, point);
        if(ans1 != -1) return ans1;
        
        int ans2 = binarySearch(arr, key, point + 1, n - 1);
        return ans2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends