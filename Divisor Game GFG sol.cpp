class Solution {
  private:
    int solve(int n,int &turn)
    {
        if(n<=0)
        {
            return turn;
        }
        n=n-1;
        turn=1-turn;
        return solve(n,turn);
    }
  public:
    bool divisorGame(int n) {
        int turn=1;
        int check=solve(n,turn);
        if(check)
        {
            return 1;
        }
        return 0;
    }
};
