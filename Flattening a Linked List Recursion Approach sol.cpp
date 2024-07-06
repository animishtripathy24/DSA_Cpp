Node* merge2Sorted(Node* list1,Node* list2)
{
    if(!list1 && !list2)
    {
        return NULL;
    }
    if(list1 && !list2)
    {
        return list1;
    }
    if(!list1 && list2)
    {
        return list2;
    }
    //now the list1 pointer will always point to the small node
    if(list2->data < list1->data)
    {
        swap(list1,list2);
    }
    Node* res = list1;
    
    while(list1 != NULL && list2 != NULL)
    {
        Node* temp=NULL;
        while(list1 != NULL && list1->data <= list2->data)
        {
            temp=list1;
            list1=list1->bottom;
        }
        temp->bottom = list2;
        swap(list1,list2);
    }
    return res;
}
Node *flatten(Node *root) {
   //base case
   if(root == NULL)
   {
       return NULL;
   }
   Node* right = flatten(root->next);
   return merge2Sorted(root,right);
}
