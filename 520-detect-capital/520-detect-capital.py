class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        temp = word[:]
        return word==temp.upper() or word==temp.lower() or word==temp.capitalize()