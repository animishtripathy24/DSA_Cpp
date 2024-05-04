/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //at first we have to make dummy node
        ListNode* dummy=new ListNode();
        //attach the dummy node with the head of the linked list
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        while(curr != NULL)
        {
            if(curr->next != NULL && curr->val == curr->next->val )
            {
                ListNode* temp=curr->next;
                while(temp != NULL && temp->val == curr->val)
                {
                    temp=temp->next;
                }
                prev->next=temp;
                curr=temp;
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
