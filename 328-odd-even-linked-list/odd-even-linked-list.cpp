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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*demo1=new ListNode(-1);
        ListNode*demo2=new ListNode(-1);
        ListNode*oddtail=demo1;
        ListNode*eventail=demo2;
        ListNode*curr=head;
        int count=1;
        
        while(curr){

            if(count%2==1){
                oddtail->next=curr;
                oddtail=oddtail->next;
    
            }
            else{
                eventail->next=curr;
                eventail=eventail->next;
                
            }
            curr=curr->next;
            count++;
            
        }
        eventail->next=NULL;
        oddtail->next=demo2->next;

        return demo1->next;

    }
};