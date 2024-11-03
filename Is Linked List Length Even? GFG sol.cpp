/*structure of a node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        int count = 0;
        struct Node* curr = *head;
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        return  !(count & 1);
    }
};
