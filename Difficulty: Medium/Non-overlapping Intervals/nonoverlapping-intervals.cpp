//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        int firstEnd = intervals[0][1];
        int count =0;
        for(int i =1; i<n; i++){
            //index 1 se start krenge
            // aur compare krenge ki 1st ka last agar chota hai 2 ke first se ya barabar hai to firsrEnd ko update kar do
            // agar aisa nhi hota to min nikalo intervals aur fristEnd ka then ise hi update kr do
            if(intervals[i][0]>=firstEnd){
                firstEnd = intervals[i][1]; // update kiye jo hai usek last terms se
            }
            
            else{
                firstEnd = min(firstEnd , intervals[i][1]);
                count = count+1;
            }
        }
        return count;        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends