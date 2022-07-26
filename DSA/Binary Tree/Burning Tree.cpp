// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function Template for C++

class Solution {
  public:
    Node* createmapping(Node* root,map<Node*, Node*> &nodetoparent,int target){
        if(root== NULL) return NULL;
        
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        nodetoparent[root]= NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                nodetoparent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodetoparent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burntree(Node* root,map<Node*, Node*> &nodetoparent){
        bool flag=0;
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(root);    //starting from targetnode
        visited[root]=1;
        
        int ans=0;
        
        while(!q.empty()){
            bool flag=0;
            int size = q.size();
            
            for(int i=0; i<size; i++){
               
                Node* front= q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    visited[front->left]=1;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    visited[front->right]=1;
                    q.push(front->right);
                }
                if(nodetoparent[front] && !visited[nodetoparent[front]]){  //to go back in binary tree
                    flag=1;
                    visited[nodetoparent[front]]=1;
                    q.push(nodetoparent[front]);
                }
            }
            if(flag==1) ans++;
        }
        
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodetoparent;
        Node* targetnode = createmapping(root,nodetoparent,target);
        int ans = burntree(targetnode,nodetoparent);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends