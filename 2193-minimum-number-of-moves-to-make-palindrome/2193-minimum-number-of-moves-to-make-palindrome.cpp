class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        vector<int> visited(n);
        int moves=0;
        int mid=-1;
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            // cout<<"for i: "<<i<<endl;
            // cout<<s[i]<<endl;
            visited[i]=1;
            int idx=n-1;
            int cnt=0;
            while(idx>i){
                if(!visited[idx]){
                    if(s[idx]==s[i]) break;
                    cnt++;
                }
                idx--;
            }
            // cout<<cnt<<endl;
            if(idx==i){
                int cnt1=0, cnt2=0;
                for(int k=0;k<i;k++){
                    if(visited[k]==2) cnt1++;
                }
                for(int k=i+1;k<n/2;k++){
                    if(visited[i]==2) cnt2++;
                }
                moves+=n/2-i+cnt1-cnt2;
                // cout<<"special: "<<n/2-i+cnt<<endl;
            }
            else{
                moves+=cnt;
            }
            visited[idx]=2;
            // for(int i:visited) cout<<i<<" "; cout<<endl;
            // for(char c:s) cout<<c<<" "; cout<<endl;
        }
        return moves;
    }
};