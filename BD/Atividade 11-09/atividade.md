# Nome: Leonardo Tomasela Leal
## RA: 170291

Departamento(**codigo_departamento**, nome, area_atuacao)
Evento(**numero_evento**,nome,edicao,descricao,#codigo_departamento)
Participante(**num_inscricao**, nome, email, instituicao)
Palestrante(**codigo_palestrante**,nome,titulacao)
Palestra(**#numero_evento**,data,horario,duracao, #codigo_palestrante)
Minicurso(**#numero_evento**,data_inicial,data_final,carga_horaria_total,qtd_vagas)
Patrocinador(**codigo_patrocinador**,categoria,nome)

Presente(**#num_inscricao**,**#numero_evento**, data)
Inscrito(**#num_inscricao**,**#numero_evento**, data_inscricao)
Patrocina(**#numero_evento**,**#codigo_patrocinador**, valor_investido)
Avalia(**#num_inscricao**, **#numero_evento**, nota_final, comentario)

# Texto comparativo:

Tanto o arquivo de modelo lógico gerado pelo brModelo quanto a tabela produzida manualmente são iguais
