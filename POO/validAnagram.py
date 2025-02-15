#Nome: Leonardo Tomasela Leal RA:170291
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letras_s = {letra: s.count(letra) for letra in set(s)}
        letras_t = {letra: t.count(letra) for letra in set(t)}
        return letras_s == letras_t