class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		vector<int>ans[2*N];
		vector<int>v;
		
		for(int i=0;i<N;i++)
		{
		    for(int j=0;j<N;j++)
		    {
		        ans[i+j].push_back(A[i][j]);
		    }
		}
		for(auto &it:ans)
		{
		    for(int i=0;i<it.size();i++)
		    {
		        v.push_back(it[i]);
		    }
		}
		return v;
	}

};
