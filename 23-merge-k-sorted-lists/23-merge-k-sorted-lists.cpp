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

struct my_compare{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:
    
    ListNode* insert(ListNode* head, ListNode* node){
        if(head==NULL) return node;
        ListNode* temp = head;
        while(temp->next) temp = temp->next;
        temp->next=node;
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, my_compare> pq;
        ListNode* head=NULL;
        for(auto i:lists){
            if(i) pq.push(i);
        }
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            if(node->next) pq.push(node->next);
            node->next=NULL;
            head = insert(head,node);
        }
        return head;
    }
};