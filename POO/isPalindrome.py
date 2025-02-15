# Nome: Leonardo Tomasela Leal 
# RA: 170291
class Solution:
    def isPalindrome(self, x: int) -> bool:
        a = str(x)
        b = a[::-1]
        if a == b:
            return True
        return False