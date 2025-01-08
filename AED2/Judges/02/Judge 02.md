Exercício referente ao **Judge 02** da matéria Algoritmo e Estrutura de dados 2

---

## Enunciado:
**Problema 2
Pares de números
Tempo limite: 0,01 s (C)**

Dado um conjunto de números inteiros distintos S e um dado número inteiro N, você deve desenvolver um programa eficiente que determine a quantidade de pares distintos de números de S cujas somas resultam em N. Neste caso, o par de números 5+15 e 15+5 deve ser considerado o mesmo par de números.

---
## Entrada:
A entrada começa com uma linha contendo |S| (1< |S| ≤ 10.000), representando a quantidade de números em S, seguido do número inteiro de N (-60.000 ≤ N ≤ 60.000). A segunda linha contém os números de S, onde para cada número {s ∈ S | -30.000 ≤ s ≤ 30.000}.

---
## Saída:
Para cada caso de teste, imprima uma linha com a quantidade de pares distintos de números cujas somas é N.

---
## Exemplos:
1. Entrada:
	`8 6 3 5 1 -2 9 8 -4 6`
	Saída:
	`2`

2. Entrada:
	`5 3 -5 3 2 -1 5`
	Saída:
	`0`

3. Entrada:
	`10 -36 18 7 22 -22 -6 -10 20 -24 -26 -18`
	Saída:
	`1`