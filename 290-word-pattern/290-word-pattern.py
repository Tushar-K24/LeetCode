class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s=s.split()
        if len(s)!=len(pattern):
            return False
        words={}
        x='abcdefghijklmnopqrstuvwxyz'
        letters = {x[i]:0 for i in range(26)}
        for i in range(len(s)):
            if s[i] not in words.keys():
                words[s[i]]=pattern[i]
                if letters[pattern[i]]: return False
                letters[pattern[i]]=1
            elif pattern[i]!=words[s[i]]:
                return False
        return True