#include<iostream>
using namespace std;

class Node{

    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this ->right = NULL;
    }
};
Node* createbst(Node* root, int data){
    if(root == NULL){
        Node* root = new Node(data);
    }
    
    if(root->data > data){
        root->left = createbst(root ->left, data);
    }
    if(root->data < data){
        root->right = createbst(root->right,data);
    }

    return root;
}
Node* minval(Node* root){}
Node* deletefrombst(Node* root, int val){
    if(root == NULL) return root;
    
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;    //NULL because no nothing is present and previous node will point to NULL 
        }

        //1 child
            // left child
            if(root->left != NULL && root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;       //we are returning nodes and deleting the target node hence root->left or root->right is used
            }
            //right child
            if(root->left == NULL && root->right != NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right)->data;
            root->data = mini;
            // root->right is used because rights node will
            // be returned after deletion at last
            root->right = deletefrombst(root->right,mini);    //***** important step used because node will be needed to found again ,,,
            return root;                                       // *** also mini is passed in place of val
        }
    }

    if(root->data > val){
        root->left = deletefrombst(root->left,val);    //root->left because it will return its value to previous node (i.e previous recursive loop)
        return root;                                    // hence return root is been added it changes value in loop as different nodes value is 
                                                        //returned every time;     
    }
    if(root->data < val){
        root->right = deletefrombst(root->right,val);
        return root;
    }
}
void takeinput(Node* root){
    int data;
    cin>>data;

    while(data != -1){
        createbst(root,data);  //data  is later because it can check if it is null or not
        cin>>data;
    }
}
int main(){

    Node* root;

    cout<<"Enter data to create bst";
    takeinput(root);
}