/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void checkParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent)
    {
        //as we have to perform the BFS Traversal we have to declare a queue data structure
        queue<TreeNode*>q;
        //at first we have to push the root
        q.push(root);
        //now we have to iterate over the queue
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left != NULL)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
        {
            return {};
        }

        //at firstwe have to create a hashMap to store the parent of all nodes
        unordered_map<TreeNode*,TreeNode*>parent;
        //now we will calla function which will identify the parents nodes and update the map
        checkParent(root,parent);

        //now we have to create a another map to store the visited nodes information
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;

        //in the queue at first we have to push the target node 
        q.push(target);

        //also we have to mark the target Node to be visited in our visited map
        visited[target]=true;

        //also we have to take a variable which will keep the count of the distance
        int curr_level=0;

        //now we iterate over the queue
        while(!q.empty())
        {
            //we have to make sure to increase the distance by one each time
            if(curr_level==k)
            {
                break;
            }
            curr_level++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                //we have to move leftward rightward and upward

                //leftward
                if(curr->left != NULL && visited[curr->left]==false)
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                //rightward
                if(curr->right != NULL && visited[curr->right]==false)
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                //upward
                if(parent[curr] != NULL && visited[parent[curr]]==false)
                {
                    visited[parent[curr]]=true;
                    q.push(parent[curr]);
                }
            }
        }

        //at last the remaning nodes at the queue data structure is our answer
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
};
