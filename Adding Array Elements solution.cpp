class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        //creating a min heap
        priority_queue<int,vector<int>,greater<int>>mini;
        for(int i=0;i<n;i++)
        {
            mini.push(arr[i]);
        }
        int count=0;
        while(mini.size()>0 && mini.top()<k)
        {
            int a=mini.top();
            mini.pop();
            if(mini.size()==0)
            {
                return -1;
            }
            int b=mini.top();
            mini.pop();
            count++;
            mini.push(a+b);
        }
        return count;
    }
};
