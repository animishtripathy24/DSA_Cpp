class Solution{
public:
    
    bool isSafe(int row,int col,vector<string>&board,int n)
    {
        int duprow=row;
        int dupcol=col;
        
        //searching for the queen in left direction
        while(col >= 0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            col--;
        }
        row=duprow;
        col=dupcol;
        
        //searching for the queen in lower diagonal
        while(row<n && col >=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            row++;
            col--;
        }
        
        row=duprow;
        col=dupcol;
        
        //searching for the queen in upper diagonal
        while(row >= 0 && col >=0)
        {
            if(board[row][col]=='Q')
            {
                return 0;
            }
            row--;
            col--;
        }
        return 1;
    }

    void solve(int col,vector<string>&board,int n,vector<int>permutation,vector<vector<int>>&ans)
    {
        //base case
        if(col == n)
        {
            ans.push_back(permutation);
            return;
        }
        //for each column we have to try for every row
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                permutation.push_back(row+1);
                solve(col+1,board,n,permutation,ans);
                board[row][col]='.';
                permutation.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<int>permutation;
        int col=0;
        vector<string>board(n);
        string str(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=str;
        }
        solve(col,board,n,permutation,ans);
        return ans;
        
    }
};
