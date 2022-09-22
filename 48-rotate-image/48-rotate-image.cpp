class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int ix = 0) {
        int n = matrix.size();
        if(ix>=n-ix) return;
        for(int i=ix;i<n-ix-1;i++){
            int pt1 = matrix[ix][i], pt2 = matrix[i][n-ix-1];
            int pt3 = matrix[n-ix-1][n-i-1], pt4 = matrix[n-i-1][ix];
            matrix[i][n-ix-1] = pt1;
            matrix[n-ix-1][n-i-1] = pt2;
            matrix[n-i-1][ix] = pt3;
            matrix[ix][i] = pt4;
        }
        rotate(matrix, ix+1);
    }
};