class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &dist, vector<int> &cnt, int root){
        for(int i:adj[root]){
            if(!visited[i]){
                visited[i]=1;
                dfs(adj,visited,dist,cnt,i);
                dist[root]+=dist[i]+cnt[i];
                cnt[root]+=cnt[i];
            }
        }
        cnt[root]++;
    }
    
    void solve(vector<vector<int>> &adj, vector<int> &visited, vector<int> &res, vector<int> &dist, vector<int> &cnt, int curr, int par){
        int n = adj.size();
        if(par==-1){
            res[curr] = dist[curr];
        }
        else{
            res[curr] = res[par] + n - 2*cnt[curr]; 
        }        
        for(int i:adj[curr]){
            if(!visited[i]){
                visited[i]=1;
                solve(adj,visited,res,dist,cnt,i,curr);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n), dist(n), cnt(n);
        visited[0]=1;
        dfs(adj,visited,dist,cnt,0);
        vector<int> res(n);
        for(int &i:visited) i=0;
        visited[0]=1;
        // for(int i:dist) cout<<i<<" "; cout<<endl;
        // for(int i:cnt) cout<<i<<" "; cout<<endl;
        solve(adj,visited,res,dist,cnt,0,-1);
        return res;
    }
};