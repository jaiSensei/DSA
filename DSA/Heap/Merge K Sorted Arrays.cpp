#include<queue>
class node{             //storing data of each node row and coloumn indexes
    public:
        int data;
        int i;
        int j;
        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
    };
    
    //when class are used then min heap compare is used 
    class compare{
        public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    };

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node* ,vector<node*> ,compare> minHeap;
        
        //step 1 : put all first coloumn data in min heap
        for(int i=0; i<k; ++i){
            node* temp = new node(kArrays[i][0],i,0);
            minHeap.push(temp);
        } 
        
        
        vector<int> ans;
        while(minHeap.size() > 0){
            node* temp = minHeap.top();             //push top element in ans vector
            ans.push_back(temp->data);
            minHeap.pop();
            
            int i= temp->i;
            int j= temp->j;
            
            while(j+1 < kArrays[i].size()){         //add next element of the selected row
                node* next = new node(kArrays[i][j+1], i, j+1);
                minHeap.push(next);
            }
        }
    return ans;
}
