class Node{
    public:
    Node *links[2];
    Node(){
        links[0]=links[1]=NULL;
    }
};

class Solution {
    Node *root;
public:
    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            bool set = (num>>i)&1;
            if(!(node->links[set])){
                node->links[set] = new Node();
            }
            node = node->links[set];
        }
    }
    
    int Xor(int num){
        int xr = 0;
        Node* node = root;
        for(int i=31;i>=0;i--){
            bool needed = 1 - (num>>i)&1;
            if(node->links[needed]){
                node = node->links[needed];
                xr += 1<<i;
            }
            else{
                node = node->links[1-needed];
            }
        }
        return xr;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root=new Node();
        for(int i:nums) insert(i);
        int mx_xor = 0;
        for(int i:nums) mx_xor = max(mx_xor,Xor(i));
        return mx_xor;
    }
};