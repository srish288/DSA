//struct Node {
//    int data;
//    Node* next;
//    Node* prev;
//    Node(int val) {
//        data = val;
//        next = nullptr;
//        prev = nullptr;
//    }
//};
void findPairs(Node* head, Node* tail, int target) {
    //write code here...
    if(head==nullptr){ 
        cout<<"[]";
        return;
        
    }
   bool yes=false;
    Node* i=head;
    Node* j=tail;
    while(i && j && i->data < j->data ){
        int sum=i->data+j->data;
        if(sum==target){
            cout<<"["<<i->data<<", "<<j->data<<"] ";
            yes=true;
             i=i->next;
              j=j->prev;
        }
        else if(sum<target){
            i=i->next;
        }
        else{
            j=j->prev;
        }
    }
    if(!yes){
       cout<<"[]";    
}
}
