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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL, *temp=NULL;
        while(list1 && list2){
            ListNode* node=NULL;
            if(list1->val<list2->val){
                node=list1;
                list1=list1->next;
            }
            else{
                node=list2;
                list2=list2->next;
            }
            if(!head){
                head=node;
                temp=head;
            }
            else{
                temp->next=node;
                temp=temp->next;
            }
        }
        if(list1){
            if(!head) head=list1;
            else temp->next=list1;
        }
        if(list2){
            if(!head) head=list2;
            else temp->next=list2;
        }
        return head;
    }
};