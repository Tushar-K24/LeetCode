class Solution {
public:
    
int minDistance(string str1, string str2) {
  // Write your code here.
  int n = str1.length(), m = str2.length();

  vector<vector<int>> v(n+1,vector<int>(m+1,0));
  for(int i = 0; i<=n ; i++){
    v[i][0]=i;
  }
  for(int j = 0; j<=m ; j++){
    v[0][j]=j;
  }
  
  for(int i = 1; i<=n ; i++){
    for(int j = 1; j<=m; j++){
      int temp = min(v[i-1][j-1],min(v[i][j-1],v[i-1][j]));
      if(str1[i-1]==str2[j-1])
        v[i][j] = v[i-1][j-1];
      else{
        v[i][j] = temp+1;
      }
    }
  }
  return v[n][m];
}

};