# Nome: Leonardo Tomasela Leal
## RA: 170921

# 1)

PESSOA(**cod_pessoa**, nome, tipo, nome_depto)
TRABALHO_CONCLUSÃO(**cod_trabalho**, titulo, data_defeta, #cod_pessoa, #cod_aluno)
ALUNO(**cod_aluno**, curso, #cod_pessoa)
CO-ORIENTADOR(#cod_pessoa,#cod_projeto)

# 2)

PROVA(**id**, tempo, consulta)
QUESTÃO(**no**, texto, #no_prova, #sub-questao)
ALTERNATIVA(**no**, texto, carta, #no_questao)
FIGURA(**no**, figura, formato)
QUESTAO_FIGURA(#no_questao, #no_figura)
