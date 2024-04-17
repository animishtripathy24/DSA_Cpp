class Solution{
    private:
    int merge(int arr[],int low,int mid,int high)
    {
        vector<int>temp;
        int left=low;
        int right=mid+1;
        int count=0;
        while(left <=mid && right <=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                count+=(mid-left+1);
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <=mid)
        {
            temp.push_back(arr[left]);
            left++;
            
        }
        while(right <=high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        //now we have to merge it into the original array
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        return count;
    }
    int mergeSort(int arr[],int low,int high)
    {
        int count=0;
        if(low>= high)
        {
            return count;
        }
        int mid=(low+high)/2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    public:
    int countPairs(int arr[] , int n ) 
    {
        for(int i=0;i<n;i++)
        {
            arr[i]=i*arr[i];
        }
        return mergeSort(arr,0,n-1);  
    }
};
