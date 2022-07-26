#include<limits.h>
#include<queue>
class node{
        public:
        int data;
        int row;
        int col;
        node(int d, int r,int c){
            data = d;
            row = r;
            col = c;
        }
    };
    class compare{
        public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    };
int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node* , vector<node*>, compare > minHeap;
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        //Step 1: pushing all first smallest element in min heap
        for(int i=0; i<k; i++){
            int element = a[i][0];              //**take element variable seperately
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element,i,0));
        }
        
        
        int start = mini;
        int end = maxi;
        
        while(minHeap.size() > 0){
            
            //for finding the minimum element among the first element of each list that were put in minheap
            node* temp = minHeap.top();
            minHeap.pop();
            
            mini= temp->data;     //top element will be the smallest
            
            if(maxi - mini < end - start){   //start and end have the final answer 
                start = mini;                // maxi and mini are used to check and miniimum is stored in starrt and end
                end = maxi;
            }
            
            if(temp->col + 1 < n){          //checkign if next elemenet of the smallest row (first element row) exist
                maxi = max(maxi, a[temp->row][temp->col + 1]);      //checking for only maxi because first element are smallest
                minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1)); //pushing in heap and continuing the for loop process agaian
            }//chote walle ka next element dala diiya
            else{
                break;     // if no more elements in a row are present then no more answer are present hence stop
            }
            
            
        }
        return end-start+1;  //+1 as per quesiton
}