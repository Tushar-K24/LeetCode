class Solution {
public:
    bool detectCapitalUse(string word) {
        int state=2; //0 for all lower, 1 for all caps
        for(int i=word.size()-1;i>=0;i--){
            if(i){
                if(word[i]>='A' and word[i]<='Z'){
                    if(state==0) return false;
                    state=1;
                }           
                else{
                    if(state==1) return false;
                    state=0;
                }
            }
            else{
                if(word[i]>='a' and word[i]<='z' and state==1) return false;
            }
        }
        return true;
    }
};