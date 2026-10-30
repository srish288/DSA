/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*> mp;
        Node* deep=NULL;
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
           Node* newnode=new Node(curr->val);
           mp[curr]=newnode;
           if(deep==NULL){
            deep=newnode;
           prev=deep;
           }
           else{
             prev->next=newnode;
             prev=newnode;

           }
           curr=curr->next;
        }
        // random pointer

        curr=head;
        Node* curr2=deep;
        while(curr){
            if(curr->random==NULL){
                curr2->random=NULL;
            }
            else{
                curr2->random=mp[curr->random];
            }
            curr=curr->next;
            curr2=curr2->next;
        }
        return deep;
    }
};