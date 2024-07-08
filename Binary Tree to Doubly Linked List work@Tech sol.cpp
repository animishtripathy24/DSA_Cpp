/* This is the Node class definition

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};
*/
void solve(Node* root,Node* &head,Node* &prev)
{
	if(root == NULL)
	{
		return;
	}
	solve(root->left,head,prev);
	if(head == NULL)
	{
		head = root;
	}
	else
	{
		prev->right = root;
		root->left = prev;
	}
	prev = root;
	solve(root->right,head,prev);
}
Node* binaryTreeToDoublyLinkList(Node* root) {
    Node* head = NULL;
	Node* prev = NULL;
	solve(root,head,root);
	return head;
}
