class Solution{
    public:
    int findSingle(int n, int arr[]){
        int xori=0;
        for(int i=0;i<n;i++)
        {
            xori=xori^arr[i];
        }
        return xori;
    }
};
