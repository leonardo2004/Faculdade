Atividade da matéria "**Arquitetura e organização de computadores**", feita utilizando **NASM**.

---

### Enunciado:
Implemente um programa em **assembly para x86** conforme as instruções especificadas:

1. O programa deve ler como entrada, nesta ordem, a hora (entre 0 e 23) de um compromisso e o minuto (entre 0 e 59).
2. Após isso, o programa deve ler a hora e o minuto em que a pessoa chegou ao compromisso.
3. O programa deve verificar se os valores digitados para horas e minutos estão dentro do intervalo esperado. Caso contrário, ele deve imprimir uma mensagem de erro e repetir a operação. (Não precisa validar se a entrada é numérica. Assuma que foram entrados números).
4. Após lidos os dados, o programa deve dizer se a pessoa chegou adiantada, atrasada ou pontualmente e quanto tempo de atraso ou adiantada chegou.

Use as mensagens abaixo para a interação com o usuário:
- Entre com a hora do compromisso: 
- Entre com os minutos do compromisso: 
- Entre com a hora de chegada:
- Entre com os minutos de chegada: 
- Hora invalida!
- Minutos inválidos!
- A pessoa chegou HH:MM adiantada. 
- A pessoa chegou HH:MM atrasada. 
- A pessoa chegou pontualmente.

Nas mensagens acima, HH e MM são a quantidade de horas e minutos que a pessoa chegou atrasada ou adiantada.
Use sempre dois dígitos para a mensagem de saída. Exemplo 01:32. Para a leitura de entrada pode ser lido com apenas um dígito.
