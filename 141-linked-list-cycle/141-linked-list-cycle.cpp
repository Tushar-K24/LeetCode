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
    bool hasCycle(ListNode *head) {
        ListNode *fast_ptr=head, *slow_ptr=head;
        do{
            if(slow_ptr) slow_ptr=slow_ptr->next;
            if(fast_ptr) fast_ptr=fast_ptr->next;
            if(fast_ptr) fast_ptr=fast_ptr->next;
        }while(slow_ptr!=fast_ptr);
        return fast_ptr;
    }
};