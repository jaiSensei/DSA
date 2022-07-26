#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size +1;
        int index = size;
        arr[size] = val;

        //comparing till the last
        while(index > 1){

            int parent = index/2;

            //max heap
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
            }
            else{
                return;
            }
        }
    }

    void deletefromheap(){
        if(size == 0) return;

        //swap the last index with first index root
        arr[1] = arr[size];

        int i = 1;
        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i +1 ;

            if(leftindex < size && arr[leftindex] > arr[i]){
                swap(arr[leftindex], arr[i]);
                i = leftindex;
            }
            else if(rightindex < size && arr[rightindex] > arr[i]){
                swap(arr[rightindex],arr[i]);
                i= rightindex;
            }
            else return;
        }
    }

    void heapify(int arr[], int n, int i){
        //base case
        if(i >= n)
            return;

        int left = 2*i;    //for  1 index heap for 0 2*i + 1
        int right = 2*i+1;
        int largest;   //to find the largest among the 3 left, right and root
        if(left <= n && arr[left] > arr[i]){    // equal to is present because starting index is 1
                largest = left;  //when larger element is found then it is swapped and processed again by changing the index to 
                                 // new swap location and recursively done again
            }
        else{ 
            largest = i; 
        }
        if(right <= n && arr[right] > arr[i]){  //same here
                largest = right;
            }

            if(largest != i){      //if left or right elements are found bigger
                swap(arr[largest],arr[i]);   //swap when bigger element is found
                heapify(arr,n,largest);
            }
        }

    void heapsort(int arr[], int n){
        int size = n;

        //left <= n and right <=n equal to is put because range is continuously changing hence it should be equal
        while(size >1){
            swap(arr[size],arr[1]);
            size--;

            heapify(arr,size,1); //i is one because whole heap is needed to heapified
        }
    }
};

int main(){

    heap h;
    h.insert(10);
    h.insert(20);

    int arr={};
    int n = h.size;

    for(int i=n/2; i>0; i++){
        h.heapify(arr,n,i);
    }
    return 0;
}