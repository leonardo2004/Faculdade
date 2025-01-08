Exercício referente ao **Judge 01** da matéria Algoritmo e Estrutura de dados 2

---

## Enunciado:

**Problema 1**
**Roteador**
**Tempo limite: 0,5 s (C)**

A empresa de telecomunicações TeleJosé deseja instalar um roteador para fornecer acesso à
internet de alta velocidade através de uma rede cabeada com uma certa quantidade de empresas
clientes em uma dada rua. Para garantir que o serviço prestado seja da melhor qualidade e
segurança possível, a TeleJosé solicita que você desenvolva um programa para calcular o local
ideal onde este servidor deverá ser instalado, de forma a minimizar a distância a todos os
clientes.

---
## Entrada:
A entrada consiste em uma linha com um caso de teste. Para cada teste, será fornecido
um número inteiro de clientes N (0 < N < 100) e uma sequência com os números inteiros de
localização de cada cliente $c_1\ , \ c_2 \ , \ ... \ , \ c_{i} \ , \ ... \ , c_{N}, (0 < c_{}i < 10000)$ na rua. Cada localização é dada como
a distância ao início da rua em uma mesma métrica (metros, por exemplo). Note que em casa de
haver algum prédio comercial, poderá haver clientes localizados na mesma numeração.

---
## Saída:
O seu programa deverá imprimir a soma mínima das distâncias da localização ideal do
roteador até cada um dos clientes. A distância entre dois locais $c_{i}$ e $c_j$ é dada por $d_{ij} = |c_i - c_j|$.

---
## Exemplos:
1. Entrada:
	`2 2 4`
	Saída:
	`2`

2. Entrada:
	`3 2 4 6`
	Saída:
	`4`