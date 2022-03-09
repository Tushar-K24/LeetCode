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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next=head;
        head=dummy;
        
        // INT_MIN ->  1 -> 2 -> 2 -> X
        
        auto prev=head;
        auto curr=head->next;
        while(curr){
            int v = curr->val;
            int cnt=0;
            auto temp=curr;
            while(curr && (curr->val==v)){
                curr=curr->next;
                cnt++;
            }
            if(cnt>1){
                prev->next=curr;
            }
            else{
                prev=temp;
            }
        }
        return head->next;
    }
};