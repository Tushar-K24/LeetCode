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
    ListNode* insert(ListNode* head, ListNode* node){
        if(node->val<head->val){
            node->next = head;
            return node;
        }
        ListNode* temp = head;
        while(temp->next!=node->next && temp->next->val<node->val)
            temp=temp->next;
        node->next = temp->next;
        temp->next = node;
        return head;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        while(temp->next){
            ListNode* curNode = temp;
            ListNode* node = temp->next;
            curNode->next = node->next;
            head = insert(head, node);
            if(curNode->next==node) curNode=node;
            temp = curNode;
        }
        return head;
    }
};