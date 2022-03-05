class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto i:edges){
            graph[i[1]].push_back(i[0]);
        }
        vector<vector<int>> ancestors(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            //applying bfs
            vector<int> visited(n); 
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                if(x!=i) ancestors[i].push_back(x);
                for(int i:graph[x]){
                    if(!visited[i]){
                        visited[i]=1;
                        q.push(i);
                    }
                }
            }
            sort(ancestors[i].begin(),ancestors[i].end());
        } 
        return ancestors;
    }
};