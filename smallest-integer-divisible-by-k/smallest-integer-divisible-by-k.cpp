class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int carry=0;
        int cnt=0;
        while(true){
            int temp_cnt=0;
            for(int i=1;i<10;i++){
                int x=k*i + carry;
                if((x%10)!=1) continue;
                while(x && ((x%10) == 1)){
                    x/=10;
                    temp_cnt++;
                }
                carry=x;
                if(x==0) return cnt+temp_cnt;
                break;
            }
            if(temp_cnt==0) return -1;
            cnt+=temp_cnt;
        }
        return -1;
    }
};