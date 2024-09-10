//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<int, int> mp;
        int left = 0, right = 0;
        int len = 0;
        int maxLength = 0;
        while(right < s.length()){
            mp[s[right]]++;
            if(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            else{
                len = right - left + 1;
                maxLength = max(maxLength, len);
            }
            right++;
        }
        if(mp.size() < k) return -1;
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends