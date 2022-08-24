class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size() or start<0) return false; 
        if(arr[start]==-1) return false;
        if(arr[start]==0) return true;
        int x = arr[start];
        arr[start] = -1;
        return canReach(arr, start + x)|canReach(arr, start-x);
    }
};