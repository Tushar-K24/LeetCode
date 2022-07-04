class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int,int>> temp;
        for(int i=0;i<ratings.size();i++) temp.push_back({ratings[i],i});
        sort(temp.begin(),temp.end());
        vector<bool> visited(ratings.size(),false);
        vector<int> candies(ratings.size());
        int cnt=0;
        for(int i=0;i<ratings.size();i++){
            if(!visited[temp[i].second]){
                candies[temp[i].second]=1;
                for(int j=temp[i].second-1;j>=0;j--){
                    if(ratings[j]>ratings[j+1]){
                        if(!visited[j]){
                            candies[j] = candies[j+1] + 1;
                            visited[j]=true;
                        }
                        else{
                            candies[j] = max(candies[j], candies[j+1]+1);
                        }
                    }
                    else break;
                }
                for(int j=temp[i].second+1;j<ratings.size();j++){
                    if(ratings[j]>ratings[j-1]){
                        if(!visited[j]){
                            candies[j] = candies[j-1] + 1;
                            visited[j]=true;
                        }
                        else{
                            candies[j] = max(candies[j], candies[j-1]+1);
                        }
                    }
                    else break;
                }
            }
        }
        for(int i:candies) cnt+=i;
        return cnt;
    }
};