/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node* ptr1 = head;
        Node* new_head=NULL;
        Node* ptr2=NULL;
        while(ptr1){
            if(mp.count(ptr1) == 0)
                mp[ptr1]=new Node(ptr1->val);
            Node* node = mp[ptr1];
            //setting node's next and random
            if(ptr1->next){ //setting next
                if(mp.count(ptr1->next)==0){
                    mp[ptr1->next]=new Node(ptr1->next->val);
                }
                node->next=mp[ptr1->next];
            }
            if(ptr1->random){ // setting random
                if(mp.count(ptr1->random)==0){
                    mp[ptr1->random]=new Node(ptr1->random->val);
                }
                node->random=mp[ptr1->random];
            }
            if(!new_head){
                new_head=node;
                ptr2=new_head;
            }
            else{
                ptr2->next=node;
                ptr2 = ptr2->next;
            }
            ptr1=ptr1->next;
        }
        return new_head;
    }
};