class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //largest nikalna hai isliye min heap
        priority_queue<int,vector<int>,greater<int> > q;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];         //storing in the same loop hence one more loop is not required do dry run for better
                if(q.size() < k){       //understanding
                    q.push(sum);
                }
                else{
                    if(sum > q.top()){    //push if bigger element is found
                        q.pop();            //refer kth largest element for better understanding
                        q.push(sum);
                    }
                }
            }
        }
        return q.top();
    }
};