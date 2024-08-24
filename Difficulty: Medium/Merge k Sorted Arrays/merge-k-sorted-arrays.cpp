//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class Info{
    public:
    int data;
    int row;
    int col;
    Info(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(Info a, Info b){
        return a.data > b.data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        priority_queue<Info, vector<Info>, compare> pq;
        // push the first k elements, from each row in the min heap
        for(int i = 0 ; i < k ; i++){
            //make the Info
            Info temp(arr[i][0], i, 0);
            pq.push(temp);
        }
        //the loop will run till elements are there in the heap (total elements)
        // in this case we can run the loop till k*k as rows == cols but in case if row length is not equal to col, 
        //this is a safe and good approach
        while(!pq.empty()){
            //extract the top element from min heap
            Info front = pq.top();
            int element = front.data;
            int currRow = front.row;
            int currCol = front.col;
            pq.pop();
            //push the element in the answer
            ans.push_back(element);
            //check whether we can access the next element in the col
            if(currCol + 1 < k){
                Info temp(arr[currRow][currCol + 1], currRow, currCol + 1);
                pq.push(temp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends