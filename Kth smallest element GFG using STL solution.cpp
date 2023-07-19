class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        //step-1 make the max heap of first k elements
        priority_queue<int>pq;
        for(int i=l;i<k;i++)
        {
            pq.push(arr[i]);
        }
        
        //step-2: from the remaining element check which one is smaller than the top element of the priority_queue
        for(int i=k;i<=r;i++)
        {
            if(arr[i]<pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step-3: return the top of the queue
        return pq.top();
    }
};
