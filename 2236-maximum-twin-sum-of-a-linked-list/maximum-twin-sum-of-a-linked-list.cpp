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
    int pairSum(ListNode* head) {
        
        vector<int>vals;
        ListNode*curr=head;
        
        while(curr){
            vals.push_back(curr->val);
            curr=curr->next;
        }
        
        int maxsum=INT_MIN;
        int n=vals.size();

        for(int i=0;i<n/2;++i){
            
            int sum=vals[i]+vals[n-1-i];
            maxsum=max(maxsum,sum);

        }
        return maxsum;
        
    }
};