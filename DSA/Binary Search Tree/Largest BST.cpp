// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    class info{
        public:
        int maxi;
        int mini;
        bool isbst;
        int size;
    };
    
    info findbstsize(Node *root, int & ans){
        if(root == NULL){
            // to return values of type class put it in curly brackets
            return {INT_MIN,INT_MAX,true,0};
        }
        
        //left and right traversals
        info left = findbstsize(root->left,ans);
        info right = findbstsize(root->right,ans);
        
        //represents the N(inoder N root) in a recursive loop 
        //used because 4 values are needed to be stored and checked and as others are class it is also stored in class
        //else it will become cubersome
        info currnode;
        
        currnode.size = left.size + right.size + 1;   // +1 very important increases the size of valid bst
        currnode.maxi = max(root->data,right.maxi);   //obvious
        currnode.mini = min(root->data,left.mini);
        
        //left ans right subtree should be valid and data should be smaller and bigger respectively
        if(left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini)){
            currnode.isbst = true;
        }
        else{
            currnode.isbst = false;
        }
        
        //if root node bst is valid store the ans
        if(currnode.isbst){
            ans = max(ans,currnode.size);
        }
        //returning so that recursive loop can continue i guess or else no use case
        //return value into left and right info class elements
        return currnode;
    }
    int largestBst(Node *root)
    {
        int ans=0;  //passed by refernce
    	info temp = findbstsize(root,ans);   //do not return temp.size 
    	return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends