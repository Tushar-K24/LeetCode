class Solution {
public:
    char findTheDifference(string s, string t) {
        char c=0;
        for(int i:s) c^=i;
        for(int i:t) c^=i;
        return c;
    }
};