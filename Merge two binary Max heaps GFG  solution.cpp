class Solution{
private:
    void heapify(vector<int>&arr,int n,int i)
    {
        int largest=i;
        int leftChild = 2*i+1;
        int rightChild=2*i+2;
    
        if(leftChild < n && arr[largest] < arr[leftChild])
        {
            largest=leftChild;
        }
        if(rightChild < n && arr[largest] < arr[rightChild])
        {
            largest=rightChild;
        }
    
        if(largest != i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step-1: merge the two vectors
        vector<int>v;
        for(auto &value:a)
        {
            v.push_back(value);
        }
        for(auto &value:b)
        {
            v.push_back(value);
        }
        //step-2:build max heap through the heapify method
        int size=v.size();
        for(int i=(size/2)-1;i>=0;i--)
        {
            heapify(v,size,i);
        }
        return v;
    }
};
