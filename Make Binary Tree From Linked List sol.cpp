void bfs(Node* head, TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* curr=q.front();
        q.pop();
        
        if(head == NULL)
        {
            return;
        }
        curr->left = new TreeNode(head->data);
        head=head->next;
        q.push(curr->left);
        
        if(head == NULL)
        {
            return;
        }
        curr->right = new TreeNode(head->data);
        head=head->next;
        q.push(curr->right);
        
        
    }
}
void convert(Node *head, TreeNode *&root) {
    root=new TreeNode(head->data);
    bfs(head->next,root);
    return;
}
