Exercício referente ao **Judge 03** da matéria Algoritmo e Estrutura de dados 2

---
## Enunciado:

**Problema 3** ;
**Registro de projetos** ;
**Limite: 0,5s (C/C++)**

Uma grande empresa de tecnologia deseja manter um registro eficiente dos projetos em que seus funcionários estão envolvidos. Para atender a essa necessidade, você deve implementar um programa que permita a organização dos projetos de forma eficiente. O programa deve ser capaz de realizar operações de inserção e consulta dos projetos associados a cada funcionário de forma eficiente.

Para tornar as operações eficientes, você deve utilizar uma árvore AVL que organiza as informações pelo nome de cada funcionário, permitindo as operações de buscas e atualizações previstas.

---
## Entrada:
Cada linha da entrada inicia-se com o número da operação a ser realizada: 1 para inserção ou atualização de um registro, 2 para busca e 0 para encerrar o programa. A operação 1 é seguida de um nome simples de até 15 caracteres e um número correspondente ao número de um projeto. Caso esse nome ainda não tenha sido inserido anteriormente, você deve inserir este novo nome. Cada funcionário será associado a um nome único. Caso contrário, adicione o novo projeto na lista de projetos no nó do nome encontrado. A operação 2 é seguida apenas do nome a ser buscado.

---
## Saída:
Para cada operação de busca, imprima a altura do nó que armazena o nome buscado e a lista de projetos registrados para esse nome em ordem de inserção separados por espaços em branco. Considere que a altura de um nó folha é 1. Caso o nome buscado não exista na árvore de busca, imprima 0.

---
## Exemplos:
1. **Entrada:**

```1 Ricardo 1999
1 Rogerio 1997
1 Zelia 1998
1 Rogerio 2002
1 Zelia 2000
1 Rogerinho 2004
1 Zelia 2003
2 Zelia
1 Karol 2007
1 Melissa 2009
1 Melissa 2010
1 Rogerinho 2005
2 Melissa
1 Melissa 2011
2 Cristovao
1 Cristovao 2008
1 Cristovao 2013
1 Melissa 2012
1 Rogerio 1996
2 Rogerio
1 Romulo 1994
1 Cristovao 2014
2 Romulo
0
```
**Saída:**
```
1 1998 2000 2003
1 2009 2010
0
2 1997 2002 1996
1 1994
```

2. **Entrada:**
```
1 Barcelos 2009
1 Confucio 2000
1 Severino 2005
1 Isabel 2006
1 Regiane 2014
2 Confucio
1 Murilo 2007
1 Barcelos 2011
1 Confucio 2012
1 Beatriz 2013
2 Barcelos
1 Mario 2008
1 Izabella 2010
2 Confucio
2 Isabel
0
```
**Saída:**
```
3 2000
1 2009 2011
1 2000 2012
4 2006
```