#Nome: Leonardo Tomasela Leal RA:170291

class Solution:
    def isValid(self, s: str) -> bool:
        open_brackets = ['(','[','{']
        close_brackets = [')',']','}']
        pilha = []
        
        for i in list(s):
            if i in open_brackets:
                pilha.append(i)
            
            #Verifica se o valor verificado é um close bracket
            elif i in close_brackets:
            
            #Caso for um close bracket, verifica se a pilha não está vazia e se o index do último elemento da pilha na lista de open brackets é o mesmo index do elemento analisado na lista de close brackets e retira o elemento da pilha
                if pilha and open_brackets.index(pilha[-1]) == close_brackets.index(i):
                    pilha.pop()
                else:
                    return False
        if pilha:
            return False
        return True