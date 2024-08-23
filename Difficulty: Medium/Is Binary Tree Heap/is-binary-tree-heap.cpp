//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isComplete(struct Node* root){
        queue<struct Node*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            struct Node* temp = q.front();
            q.pop();
            if(temp == NULL){
                flag = true;
            }
            else{
                if(flag) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
    pair<int, bool> isMaxHeap(struct Node* root){
        if(root == NULL){
            return make_pair(INT_MIN, true);
        }
        if(root->left == NULL && root->right == NULL){
            return make_pair(root->data, true);
        }
        auto left = isMaxHeap(root->left);
        auto right = isMaxHeap(root->right);
        
        if(left.first < root->data && right.first < root->data && left.second && right.second){
            return make_pair(root->data, true);
        }
        return make_pair(max(left.first, right.first), false);
    }
    bool isHeap(struct Node* tree) {
        if(isComplete(tree)){
            auto ans = isMaxHeap(tree);
            if(ans.second) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends