class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1=0,idx2=0;
        int n=version1.size(), m=version2.size();
        while(idx1<n || idx2<m){
            int curr1 = 0;
            int curr2 = 0;
            while(idx1<n && version1[idx1]!='.'){
                curr1*=10;
                curr1+=(version1[idx1]-'0');
                idx1++;
            }
            while(idx2<m && version2[idx2]!='.'){
                curr2*=10;
                curr2+=(version2[idx2]-'0');
                idx2++;
            }
            if(curr1<curr2) return -1;
            if(curr1>curr2) return 1;
            idx1++;
            idx2++;
        }
        return 0;
    }
};