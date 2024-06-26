int findFloor(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low <= high)
    {
        int mid=low+((high-low)>>1);
        if(arr[mid]<= x)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans==-1?-1:arr[ans];
}
int findCeil(int arr[],int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low <= high)
    {
        int mid=low+((high-low)>>1);
        if(arr[mid]>= x)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans==-1?-1:arr[ans];
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    pair<int,int>p;
    p.first=findFloor(arr,n,x);
    p.second=findCeil(arr,n,x);
    return p;
}
