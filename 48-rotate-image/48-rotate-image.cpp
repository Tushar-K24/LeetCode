class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<=i) swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int r=0;r<n;r++){
            for(int i=0,j=n-1;i<j;i++,j--){
                swap(matrix[r][i],matrix[r][j]);
            }
        }
    }
};