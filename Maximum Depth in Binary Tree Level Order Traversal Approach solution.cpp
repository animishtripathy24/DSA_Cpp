class Solution {
public:
    int maxDepth(TreeNode* root) {
        //edge case
        if(root == NULL)
        {
            return 0;
        }
        int level=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
            level++;
        }
        return level;
        
    }
};
