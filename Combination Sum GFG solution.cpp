class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(int index,int target,vector<int>A,vector<int>&ds,vector<vector<int>>&ans)
    {
        //if the index exceeds the size and target becomes zero
        if(index==A.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        //picking the index value
        if(A[index]<=target)
        {
            ds.push_back(A[index]);
            solve(index,target-A[index],A,ds,ans);
            ds.pop_back();
        }
        
        //for skipping the duplicates 
        while(index+1 < A.size() && A[index]==A[index+1])
        {
            index++;
        }
        
        //not picking
        solve(index+1,target,A,ds,ans);
        
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        //at first we have to declare the 2d array
        vector<vector<int>>ans;
        
        
        //sorting the vector
        sort(A.begin(),A.end());
        
        //we have to carry a data structure
        vector<int>ds;
        
        //then we have to declare the index
        int index=0;
        
        //recursive function
        solve(index,B,A,ds,ans);
        
        //returning the ans
        return ans;
    }
};
