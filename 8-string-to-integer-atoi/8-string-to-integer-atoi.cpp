class Solution {
public:
    int myAtoi(string s) {
        long x = 0;
        int curr = 0;
        while(curr<s.size() && s[curr]==' ') curr++;
        bool neg = false;
        if(s[curr]=='+' || s[curr]=='-'){
            if(s[curr]=='-') neg=true;
            curr++;
        }
        while(curr<s.size() && s[curr]>='0' && s[curr]<='9'){
            x*=10;
            x+=s[curr]-'0';
            curr++;
            if(x>INT32_MAX){
                x = INT32_MAX;
                x+=2;
                break;
            }
        }
        if(neg){
            x*=-1;
            if(x<INT32_MIN) x = INT32_MIN;
        }
        else if(x>INT32_MAX){
            x = INT32_MAX;
        }
        return x;
    }
};