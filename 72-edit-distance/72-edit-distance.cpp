class Solution {
public:
    int sol_dp(vector<vector<int>> &dp, string &word1, string &word2, int n, int m){
        if(n==0) return m;
        if(m==0) return n;
        int &ans = dp[n][m];
        if(ans!=-1) return ans;
        if(word1[n-1]==word2[m-1]) return ans = sol_dp(dp, word1, word2, n-1, m-1);
        //replace the character
        ans = sol_dp(dp, word1, word2, n-1, m-1) + 1;
        //erase the character
        ans = min(ans, sol_dp(dp, word1, word2, n-1,m) + 1);
        //insert the character
        ans = min(ans, sol_dp(dp, word1, word2, n, m-1) + 1);
        return ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,vector<int>(word2.size() + 1, -1));
        return sol_dp(dp, word1, word2, word1.size(), word2.size());
    }
};