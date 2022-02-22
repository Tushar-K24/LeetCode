class Solution {
public:
    int titleToNumber(string columnTitle) {
        int col_num=0;
        long long x=1;
        for(int i=columnTitle.size()-1;i>=0;i--){
            col_num+=(columnTitle[i]-'A'+1)*x;
            x*=26;
        }
        return col_num;
    }
};