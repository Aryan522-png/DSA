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
    ListNode* reverse(ListNode*head){

        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;

        while(curr!=NULL){
            
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }

    void insertAtTail(ListNode*&head,ListNode*&tail,int digit){

        ListNode*temp=new ListNode(digit);
        if(head==NULL){
            head=temp;
            tail=temp;
            
        }
        else{
            tail->next=temp;
            tail=temp;
        }



    }    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        

        ListNode*head=NULL;
        ListNode*tail=NULL;

        int carry=0;

        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;

            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;

            }


            int digit=sum%10;
            carry=sum/10;
            insertAtTail(head,tail,digit);
        }

        return head;

        
    }
};