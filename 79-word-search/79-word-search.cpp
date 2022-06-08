class Solution {
public:
    bool exists(vector<vector<char>>& board, vector<vector<bool>> &visited, string &word, int r, int c, int ix){
        if(ix == word.size()) return true;
        if(r<0 || r>= board.size()) return false;
        if (c<0 || c>=board[0].size()) return false;
        if(board[r][c]!=word[ix]) return false;
        if(visited[r][c]) return false;
        bool ans=false;
        visited[r][c]=true;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for(int i=0;i<4;i++){
            int r_new = r + dx[i];
            int c_new = c + dy[i];
            ans|=exists(board,visited,word,r_new,c_new,ix+1);
            if(ans)
                break;
        }
        visited[r][c]=false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        bool ok=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                ok|=exists(board, visited, word, i,j,0);
                if(ok) return ok;
            }
        }
        return ok;
    }
};