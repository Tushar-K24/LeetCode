class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int m = arr.size()-1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(i==n-1){
                    arr[m]=arr[i];
                    m--;
                }
                n--;
            }
        }
        n--;
        while(n>=0){
            arr[m] = arr[n];
            m--;
            if(arr[n]==0){
                arr[m] = arr[n];
                m--;
            }
            n--;
        }
    }
};