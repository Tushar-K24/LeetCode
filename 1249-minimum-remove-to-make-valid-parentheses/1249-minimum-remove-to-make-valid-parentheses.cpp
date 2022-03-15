class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> s1,s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else if(s[i]==')'){
                if(s1.empty()) s2.push(i);
                else s1.pop();
            }
        }
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(!s1.empty() && i==s1.top()) s1.pop();
            else if(!s2.empty() && i==s2.top()) s2.pop();
            else{
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};