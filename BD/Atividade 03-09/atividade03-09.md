# Nome: Leonardo Tomasela Leal
## RA: 170291

# 1)

## PACIENTE
* Chaves primárias: 
    1. CodPaciente
* Chaves estrangeiras:
    1. CodMunicipio_residencia

## ESTABELECIMENTO:
* Chaves primárias:
    1. CodEstabelecimento

* Chaves estrangeiras:
    1. CodMunicipio

## MUNICIPIO:
* Chaves primárias:
    1. CodMunicipio 

* Chaves estrangeiras:

## INTERNAÇÃO:
* Chaves primárias:
    1. CodInternação
    2. CodEstab

* Chaves estrangeiras:
    1. CodPaciente
    2. CodEstab

## CID:
* Chaves primárias:
    1. CodCid

* Chaves estrangeiras:

## PROCEDIMENTO:
* Chaves primárias:
    1. CodProcedimento

* Chaves estrangeiras:

## INTERNACAO CID:
* Chaves primárias:
    1. CodInternacao
    2. CodCID

* Chaves estrangeiras:
    1. CodInternacao
    2. CodCID

## PACIENTE_DOENCA:
* Chaves primárias:
    1. CodPaciente
    2. CodCID
    3. data_diagnostico

* Chaves estrangeiras:
    1. CodPaciente
    2. CodCID

## INTERNACAO_PROCEDIMENTO
* Chaves primárias:
    1. CodInternacao
    2. CodEstab
    3. CodProcedimento

* Chaves estrangeiras:
    1. CodInternacao
    2. CodEstab
    3. CodProcedimento

# 2)

## a) Inserir um novo estabelecimento
Garantir que a chave estrangeira CodMunicipio seja não nula e válida.

## b) Excluir um município
Garantir que nínguem referencie o código do município excluído.

## c) Alterar o código de um CID
Garantir que os campos que referenciam o CID cujo código foi alterado sejam alterados para refletirem o novo código do CID.

## d) Inserir uma nova internação
Garantir que a chave estrangeira CodEstab seja não nula e válida.

## e) Excluir uma internação
Garantir que nínguem referencie o código de internação excluído
