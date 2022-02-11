class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq_dic, prev = {}, -1
        for c in s1:
            if c not in freq_dic.keys():
                freq_dic[c]=0
            freq_dic[c]+=1
            
        for i in range(len(s2)):
            if len(freq_dic)==0:
                return True
            elif s2[i] not in freq_dic.keys():
                prev+=1
                while prev<i and s2[prev]!=s2[i]:
                    if s2[prev] not in freq_dic.keys():
                        freq_dic[s2[prev]]=0
                    freq_dic[s2[prev]]+=1
                    prev+=1
            else:
                freq_dic[s2[i]]-=1
                if freq_dic[s2[i]]==0:
                    freq_dic.pop(s2[i])
        return len(freq_dic)==0