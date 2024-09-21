class Solution {
private:
    void solve(int currNum,int n,vector<int>&ans)
    {
        if(currNum > n)
        {
            return;
        }

        //add the element in the given vector
        ans.push_back(currNum);

        for(int append = 0;append <= 9;append++)
        {
            int newNum = currNum * 10 + append;
            if(newNum > n)
            {
                return;
            }
            solve(newNum , n , ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        //at first we will declare an vector
        vector<int>ans;
        for(int startNum = 1 ; startNum<=9 ; startNum++) {
            solve(startNum, n, ans);
        }
        return ans;
    }
};
