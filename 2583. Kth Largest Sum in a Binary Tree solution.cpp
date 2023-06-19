/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //check whether root is null
        if(root == NULL)
        {
            return -1;
        }
        //building a max heap
        priority_queue<long long>pq;

        //creating a queue for leval order traversal
        queue<TreeNode*>q;
        //firstly we have to push the root into the queue
        q.push(root);

        while(!q.empty())
        {
            int size =q.size();
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                //if the left child exist then add it into the queue
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                //if the right child exist then add it into the queue
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                } 
                sum+=temp->val;
            }
            pq.push(sum);
        }
        if(pq.size()<k)
        {
            return -1;
        }
        while(--k)
        {
            pq.pop();
            
        }
        return pq.top();
        
    }
};
