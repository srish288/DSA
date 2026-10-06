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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL){
             return head;
        }
        ListNode* l1= reverse(head);
        ListNode* curr=l1;
        int maxseen=curr->val;
        ListNode* prev=NULL;
        while(curr!=NULL){
            if(curr->val<maxseen){
                ListNode* nextnode=curr->next;
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                maxseen=curr->val;
                prev=curr;
                 curr=curr->next;
            }
           
        }
           return reverse(l1);
    } 
};