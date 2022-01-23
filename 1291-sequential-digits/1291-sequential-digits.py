class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        dig,n,ones,res = len(str(low)),0,0,[]
        for i in range(1,dig+1):
            n=n*10 + i
            ones = ones*10 + 1
        temp = n
        while temp<=high:
            if temp>=low: res.append(temp)
            temp+=ones
            if temp%10 == 0:
                ones = ones*10 + 1
                dig+=1
                n = n*10 + dig
                temp = n
        return res
            