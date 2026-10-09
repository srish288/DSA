/*class Node
{
    public:
    int val;
    Node* next;
    Node* child;
    Node(int val)
    {
        next = child = NULL;
        this->val = val;
    }
};*/

Node* ftail(Node* head){
   if(head==NULL){
       return NULL;
   }
   Node* curr= head;
   while(curr!=NULL){
       if(curr->child!=NULL){
           Node* nextnode=curr->next;
           Node* chead=curr->child;
           Node* ctail=ftail(chead);
           curr->next=chead;
           curr->child=NULL;
           ctail->next=nextnode;
           curr=ctail;
           
       }
       if(curr->next!=NULL){
           curr=curr->next;
       }
       else{
           break;
       }
   }
   return curr;
}
Node* flatten(Node* head) {
    ftail(head);
    return head;
}