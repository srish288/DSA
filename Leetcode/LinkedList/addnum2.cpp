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
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d1=reverse(l1);
        ListNode* d2=reverse(l2);
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        int digit=0;
        while(d1!=NULL || d2!=NULL|| carry!=0){
            int sum=carry;
            if(d1!=NULL){
                sum+=d1->val;
                d1=d1->next;
            }
            if(d2!=NULL){
                sum+=d2->val;
                d2=d2->next;
            }
            digit=sum%10;
            carry=sum/10;
            temp->next=new ListNode(digit);
            temp=temp->next;

        }
        return reverse(dummy->next);

        // same code as add

        // then reverse the ans and move ;
    }
};