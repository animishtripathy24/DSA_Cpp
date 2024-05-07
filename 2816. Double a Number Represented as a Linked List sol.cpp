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
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr != NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void insertAtTail(ListNode* &tail,ListNode* curr)
    {
        tail->next=curr;
        tail=tail->next;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead=reverse(head);
        int carry=0;
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        ListNode* curr=newHead;
        while(curr || carry)
        {
            int mul=0;
            if(curr != NULL)
            {
                mul=curr->val * 2;
                curr=curr->next;
            }
            mul+=carry;
            carry=mul/10;
            ListNode* newNode=new ListNode(mul%10);
            insertAtTail(temp,newNode);
        }
        return reverse(dummy->next);
    }
};
