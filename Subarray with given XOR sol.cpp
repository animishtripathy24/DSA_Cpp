int Solution::solve(vector<int> &A, int B) {
    int count=0;
    int xori=0;
    unordered_map<int,int>m;
    m[xori]=1;
    for(int i=0;i<A.size();i++)
    {
        xori=xori^A[i];
        count+=m[xori^B];
        m[xori]++;
    }
    return count;
}
