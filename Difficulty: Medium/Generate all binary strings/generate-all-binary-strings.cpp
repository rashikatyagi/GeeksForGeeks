//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateStrings(int &num, string currstring, vector<string> &ans) {
        int len = currstring.length();
        if(len == num + 1) return;
        if(len == num){
            ans.push_back(currstring);
            return;
        }
        if(currstring != "" && currstring.back() == '1'){
            generateStrings(num, currstring + '0', ans);
        }
        else{
            generateStrings(num, currstring + '0', ans);
            generateStrings(num, currstring + '1', ans);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> answer;
        generateStrings(num, "", answer);
        return answer;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends