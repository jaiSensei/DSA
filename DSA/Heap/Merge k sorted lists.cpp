/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<queue>
#include<bits/stdc++.h>

//for min heap
class compare{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*, vector<Node<int>*>, compare > minHeap;
    int k = listArray.size();

    //step 1 : putting first element of all lists in heap
    for(int i=0; i<k; i++){
        if(listArray[i] != NULL)    ///**imp check
        { minHeap.push(listArray[i]);}
    }
    
    Node<int>* head= NULL;
    Node<int>* tail = NULL;
    
    while(minHeap.size() > 0){
        Node<int>* top = minHeap.top();     //store top
        minHeap.pop();
        
        if(top->next != NULL){              //next element of list which has smallest element
            minHeap.push(top->next);
        }
        if(head == NULL){                   //when smallest element from first element of all linked list is not found
            head = top;
            tail = top;
        }
        else{                               //intially top and tail point to same address and this also increases the tail index
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
