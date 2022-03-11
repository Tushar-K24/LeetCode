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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len=1;
        auto temp=head;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        k%=len;
        len -= k;
        if(k==0) return head;
        temp=head;
        for(int i=1;i<len;i++){
            temp=temp->next;
        }
        auto l1 = head;
        auto l2 = temp->next;
        temp->next=NULL;
        temp=l2;
        while(temp->next) temp=temp->next;
        temp->next=l1;
        return l2;
    }
};