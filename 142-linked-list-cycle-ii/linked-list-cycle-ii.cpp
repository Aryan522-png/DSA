/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==NULL || head->next==NULL ){
            return NULL;
        }

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL && fast->next!=NULL){

            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){

                int index=0;

                ListNode*entry=head;

                while(entry!=slow){

                    entry=entry->next;
                    slow=slow->next;
                    index++;

                }
                cout<<"tail connect to node index"<<index<<endl;
                return entry;
            }
        }
        cout<<"no cycle"<<endl;
        return NULL;


        
    }
};