class Solution
{
    private:
    int solve(Node* root,int &moves)
    {
        if(!root)
        {
            return 0;
        }
        int left = solve(root->left,moves);
        int right = solve(root->right,moves);
        moves+=abs(left)+abs(right);
        return (root->key + left + right) - 1;
    }
    public:
    int distributeCandy(Node* root)
    {
        int moves = 0;
        solve(root,moves);
        return moves;
    }
};
