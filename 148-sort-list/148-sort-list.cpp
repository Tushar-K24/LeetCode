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
    ListNode* mergeList(ListNode* head1, ListNode* head2){
        ListNode* head=NULL;
        ListNode* temp=NULL;
        while(head1 && head2){
            if(head1->val < head2->val){
                if(head==NULL){
                    head=head1;
                    temp=head;
                }
                else{
                    temp->next=head1;
                    temp=temp->next;
                }
                head1 = head1->next;
                temp->next=NULL;
            }
            else{
                if(head==NULL){
                    head=head2;
                    temp=head;
                }
                else{
                    temp->next=head2;
                    temp=temp->next;
                }
                head2 = head2->next;
                temp->next=NULL;
            }
        }
        if(head1) temp->next=head1;
        if(head2) temp->next=head2;
        return head;
    }
    
    ListNode* sortList(ListNode* head) { //solving using merge sort
        if((!head) || (!head->next)) 
            return head;
        //finding the middle pointer
        ListNode* slow_ptr=head, *fast_ptr = head;
        while(fast_ptr && fast_ptr->next && fast_ptr->next->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        // cout<<slow_ptr->val<<endl;
        ListNode* head1 = head;
        ListNode* head2 = slow_ptr->next;
        slow_ptr->next=NULL;
        head1 = sortList(head);
        head2 = sortList(head2);
        head=mergeList(head1,head2);
        return head;
    }
};