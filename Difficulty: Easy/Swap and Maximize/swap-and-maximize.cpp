//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> final_arr(n);
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = n - 1;
        int index = 0;
        while(left < right){
            final_arr[index++] = arr[left++];
            final_arr[index++] = arr[right--];
        }
        if(n & 1) final_arr[n - 1] = arr[n / 2];
        long long answer = abs(final_arr[0] - final_arr[n - 1]);
        for(int i = 0 ; i < n - 1 ; i++){
            answer += abs(final_arr[i] - final_arr[i + 1]);
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends