// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void presuc(Node* root, Node*& pre, Node*& suc, int data){
    if(root == NULL) return;       //base case
    
    if(root->key == data){          //base case 2

        //checking left side for largest element in left because it will be previos element in inorder.
        if(root->left != NULL){
            Node* leftans = root->left;
            while(leftans != NULL){
                pre = leftans;
                leftans = leftans->right;     //** it is right because largest element will be at right of left part
            }
        }
        
        //similarly here
        if(root->right != NULL){
            Node* rightans = root->right;
            while(rightans != NULL){
                suc = rightans;
                rightans = rightans->left;   //** it is left
            }
        }
        return;         //*** returns value of predecessor and successor when data is found, if it is not found then runtime error
    }
    
    //present in one side
    //i.e finding the data
    if(root->key > data){
        suc = root;             // if no child nodes are present then storing value of possible successor
        presuc(root->left, pre, suc, data); // will get data and next if wont run and fuction ends
    }
    if(root->key < data){
        pre = root;                 //if no child nodes are present then storing value of possible predecessor
        presuc(root->right, pre, suc, data);
    }
    
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
{

    pre = NULL;
    suc = NULL;
    
    presuc(root,pre,suc,data);


}