class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        int prev = 0;
        for(int i=0; i<numRows; i++){
            if(i==0){
                triangle.push_back({1});
            }
            else{
                prev = 0;
                triangle.push_back({});
                for(int j = 0; j < i; j++){
                    triangle[i].push_back(prev + triangle[i-1][j]);
                    prev = triangle[i-1][j];
                }
                triangle[i].push_back(1);
            }
        }                
        return triangle;
    }
};