// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int idx)
    {
        // Find largest of node and its children
        if (idx >= n)
            return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        int max;
        if (l < n && arr[l] > arr[idx])
            max = l;
        else
            max = idx;
        if (r < n && arr[r] > arr[max])
            max = r;
     
        // Put maximum value at root and
        // recur for the child with the
        // maximum value
        if (max != idx) {
            swap(arr[max], arr[idx]);
            heapify(arr, n, max);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step 1
        vector<int> ans;
        for(auto i:a)
            ans.push_back(i);
        
        for(auto j:b)
            ans.push_back(j);
        
        
        //step 2
        int size = n+m;
        for(int i=(size/2) - 1; i>=0; i--){   //used heapify to make the maxheap 
                                              // = and not equal to should be carefully used when index of heaps change
            heapify(ans,size,i);
        }
        
        
            
        return ans;
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends