/*
struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        if(mat.size() == 0)
        {
            return NULL;
        }
        int n = mat.size();
        Node* res = new Node(mat[0][0]);
        Node* temp = res;
        for(int i=1;i<n;i++)
        {
            Node* newNode = new Node(mat[0][i]);
            temp->right = newNode;
            temp = newNode;
        }
        temp = res;
        Node* start = res;
        Node* up = res;
        for(int i=1;i<n;i++)
        {
            Node* newNode = new Node(mat[i][0]);
            start->down = newNode;
            up=start->right;
            start = start->down;
            temp = start;
            for(int j=1;j<n;j++)
            {
                Node* newNode1= new Node(mat[i][j]);
                temp->right = newNode1;
                temp = newNode1;
                up->down = newNode1;
                up = up->right;
            }
            
        }
        return res;
    }
};
