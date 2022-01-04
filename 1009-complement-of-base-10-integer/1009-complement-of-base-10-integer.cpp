class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int x=1;
        while(x<=n){
            x<<=1;
        }
        x--;
        return x^n;
    }
};