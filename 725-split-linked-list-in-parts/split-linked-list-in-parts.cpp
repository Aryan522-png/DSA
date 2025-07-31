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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> result(k, nullptr);
        int length=0;
        ListNode*curr=head;

        while(curr){
            length++;
            curr=curr->next;
        }

        int partlength=length/k;
        int extraspace=length%k;

        curr=head;

        for(int i=0;i<k;i++){

            result[i]=curr;
            int thispartsize=partlength+(i<extraspace ? 1:0);

            for(int j=1;j<thispartsize;j++){
                if(curr) curr=curr->next;
            }

            if(curr){
                ListNode*nextpart=curr->next;
                curr->next=NULL;
                curr=nextpart;
            }
        }

        return result;
        
    }
};