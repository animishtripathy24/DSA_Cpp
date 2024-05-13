/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(Node* head, int M, int N)
    {
        // At first we have to make a dummy node
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node* curr = dummy;
    
        while (curr != NULL)
        {
            // Move curr by M steps
            for (int i = 0; i < M && curr != NULL; i++)
            {
                curr = curr->next;
            }
    
            // If curr has reached the end, exit
            if (curr == NULL)
                break;
    
            // Set prev to NULL before moving temp
            Node* prev = NULL;
            Node* temp = curr;
            
            // Move temp by N+1 steps
            for (int i = 0; i <= N && temp != NULL; i++)
            {
                prev = temp;
                temp = temp->next;
            }
    
            // Set the next pointer of curr to temp
            curr->next = temp;
    
            // Move curr back to prev to maintain the distance of M
            curr = prev;
        }
    
        head = dummy->next;
        delete dummy; // Free the memory for dummy node
    }

};
