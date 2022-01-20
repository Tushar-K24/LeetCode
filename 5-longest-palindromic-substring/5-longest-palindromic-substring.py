class Solution:
    def longestPalindrome(self, s: str) -> str:
        def find_length(l,r):
            while l>=0 and r<len(s):
                if s[l]!=s[r]:
                    break
                l-=1
                r+=1
            l+=1
            r-=1
            return l,r
        
        l,r = 0,0
        for i in range(len(s)):
            st,en = find_length(i,i) #checking odd lengths
            if r-l<en-st:
                l,r = st,en
            st,en = find_length(i,i-1) #checking even lengths
            if r-l<en-st:
                l,r = st,en    
        return s[l:r+1]