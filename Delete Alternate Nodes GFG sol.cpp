/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while(curr != NULL)
        {
            if(count & 1)
            {
                prev = curr;
            }
            else
            {
                Node* nodeToDelete = curr;
                prev->next = curr->next;
                delete nodeToDelete;
            }
            curr=curr->next;
            count++;
        }
    }
};
