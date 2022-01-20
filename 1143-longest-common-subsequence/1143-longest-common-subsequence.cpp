class Solution {
public:
    int sol_dp(vector<vector<int>> &dp, string &A, string &B, int n, int m){
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(A[n-1]==B[m-1]) return dp[n][m] = 1 + sol_dp(dp, A, B, n-1, m-1);
        dp[n][m] = sol_dp(dp,A,B,n-1,m);
        dp[n][m] = max(dp[n][m], sol_dp(dp,A,B,n,m-1));
        return dp[n][m];
    }
    
    int longestCommonSubsequence(string A, string B) {
        int n=A.size();
        int m=B.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return sol_dp(dp,A,B,n,m);
    }
};