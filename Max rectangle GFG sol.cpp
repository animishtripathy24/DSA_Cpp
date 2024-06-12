class Solution{
  private:
    void findRightSmall(int *arr,int n,vector<int>&rightSmall)
    {
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[i] < arr[s.top()])
            {
                rightSmall[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
    }
    void findLeftSmall(int *arr,int n,vector<int>&leftSmall)
    {
        stack<int>s;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[i] < arr[s.top()])
            {
                leftSmall[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
     int getMaxArea(int *arr, int &n)
    {
        vector<int>leftSmall(n,-1);
        vector<int>rightSmall(n,-1);
        findLeftSmall(arr,n,leftSmall);
        findRightSmall(arr,n,rightSmall);
        for(int i=0;i<rightSmall.size();i++)
        {
            if(rightSmall[i]==-1)
            {
                rightSmall[i]=n;
            }
        }
        int maxiArea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int breadth=arr[i];
            int length=rightSmall[i]-leftSmall[i]-1;
            int newArea=length*breadth;
            maxiArea=max(maxiArea,newArea);
        }
        return maxiArea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        //at first we have to find the area for the first column
        int area=getMaxArea(M[0],m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] != 0)
                {
                    M[i][j]+=M[i-1][j];
                }
                else
                {
                    M[i][j]=0;
                }
            }
            area= max(area,getMaxArea(M[i],m));
        }
        
        return area;
    }
};
