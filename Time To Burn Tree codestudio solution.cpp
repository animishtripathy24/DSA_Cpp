#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preorder(BinaryTreeNode<int>* root,int &start,BinaryTreeNode<int>* &targetNode)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==start)
    {
        targetNode=root;
    }
    preorder(root->left,start,targetNode);
    preorder(root->right,start,targetNode);
}

void findParents(BinaryTreeNode<int>* root,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&m)
{
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        if(curr->left != NULL)
        {
            m[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right != NULL)
        {
            m[curr->right]=curr;
            q.push(curr->right);
        }
        
    }
    
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
        BinaryTreeNode<int>* targetNode;
        //to keep the track of the parent node we use a hashMap
        unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parent;
        findParents(root,parent);
        preorder(root,start,targetNode);
        //to keep track of the visited node we have to use another hashMap
        unordered_map<BinaryTreeNode<int>*,bool>visited;
        queue<BinaryTreeNode<int>*>q;
        q.push(targetNode);
        visited[targetNode]=true;
        int curr_level=0;
        while(!q.empty())
        {
            int size=q.size();
            curr_level++;
            for(int i=0;i<size;i++)
            {
                BinaryTreeNode<int>* curr=q.front();
                q.pop();
                if(curr->left && visited[curr->left]==false)
                {
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && visited[curr->right]==false)
                {
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent[curr] && visited[parent[curr]]==false)
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
                
            }
        }
        return curr_level-1;
}
