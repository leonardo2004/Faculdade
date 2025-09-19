import pandas as pd

situacao_converter_old = ['Não entrei em contato ainda','Não entrei em contato ainda','Confirmado','Proposta Feita']
situacao_converter_new = ['Não Contactadas','1º Contato','Presentes','Apresentação de Proposta/Reunião']

colunas_converter = {
    'Empresas' : 'Nome da conta',
    'Proprietário' : 'Administrador da conta',
    'Situação' : 'Status'
}

new = pd.read_csv(r'C:\Users\leo20\Documents\Coding\Faculdade\CIAP\DOCS TO NOTION\new.csv',header=0)
new = new.dropna(subset='Nome da conta')
new = new.set_index('Nome da conta')

old = pd.read_csv(r'C:\Users\leo20\Documents\Coding\Faculdade\CIAP\DOCS TO NOTION\old.csv',header=0,encoding='latin-1', sep=';')
old = old.dropna(subset='Empresas')
old = old.set_index('Empresas')

old = old.rename(columns=colunas_converter)
old = old.drop(columns=['Último contato','Data para  cobrar'])

contatos = old.dropna(subset='Contato')
contatos_email = contatos[contatos['Contato'].str.contains('@')]
contatos_telefone = contatos[contatos['Contato'].str.contains('wa.me')]

#Filtrando por telefones ou emails existentes
contatos_telefone = contatos_telefone.rename(columns={'Contato':'Número de telefone'})
contatos_email = contatos_email.rename(columns={'Contato':'E-mail de contato'})
new = pd.concat([new,contatos_telefone])
new = pd.concat([new,contatos_email])


#Status converter
new['Status'] = new['Status'].replace(to_replace=situacao_converter_old, value=situacao_converter_new)


new = new.rename(columns={'Representante':'Contato'})
new['Número de telefone'] = new['Número de telefone'].str.replace(r'[^0-9]', '', regex=True)
new = new.fillna(value='')
print(new) 

new.to_csv('teste.csv')