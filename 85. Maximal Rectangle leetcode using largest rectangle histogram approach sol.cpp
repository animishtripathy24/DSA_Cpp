class Solution {
private:
    void findRightSmall(vector<int>&arr,int n,vector<long long>&rightSmall)
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
    void findLeftSmall(vector<int>&arr,int n,vector<long long>&leftSmall)
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

    int getMaxArea(vector<int>&arr, int n)
    {
        vector<long long>leftSmall(n,-1);
        vector<long long>rightSmall(n,-1);
        findLeftSmall(arr,n,leftSmall);
        findRightSmall(arr,n,rightSmall);
        // for(auto it:leftSmall)
        // {
        //     cout << it << " ";
        // }
        // cout << endl << endl;
        // for(auto &it:rightSmall)
        // {
        //     cout << it << " ";
        // }
        // cout << endl << endl;
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>ans(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    ans[i][j]=1;
                }
                else
                {
                    ans[i][j]=0;
                }
            }
        }
        int area = getMaxArea(ans[0],ans[0].size());

        for(int i=1;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                if(ans[i][j] != 0)
                {
                    ans[i][j]+=ans[i-1][j];
                }
                else
                {
                    ans[i][j]=0;
                }
            }
            area=max(area,getMaxArea(ans[i],ans[i].size()));
        }
        return area;

    }
};
