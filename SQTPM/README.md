# O QUE É O SQTPM?

O SQTPM é um site utilizado pelo professor para envio de trabalhos e correção automática, onde os problemas são no estilo problemas de maratonas de computação, utilizando as estruturas estudadas e desenvolvidas nas aulas é preciso resolver os problemas apresentados. Somente os alunos cadastrados na disciplina tem acesso, portanto aqui são apresentados os problemas desenvolvidos ao longo do semestre em que realizei a matéria.

# 00-warmup

Escreva um programa que leia 2 valores inteiros e armazene-os nas variáveis A e B.

Efetue a soma de A e B atribuindo o seu resultado na variável X.

Imprima X conforme exemplo apresentado abaixo.

Não apresente mensagem alguma além daquilo que está sendo especificado e não esqueça de imprimir o fim de linha após o resultado, caso contrário, você receberá a mensagem "saída com formatação incorreta".

## Especificações de entrada e saída

### Entrada

A entrada contém 2 valores inteiros.

### Saída

Imprima a mensagem "X = " (letra X maiúscula) seguido pelo valor da variável X e pelo final de linha. Cuide para que tenha um espaço antes e depois do sinal de igualdade, conforme o exemplo abaixo.

## Exemplos

### Exemplo 1

| Entrada |
| ------- |

```
10
9
```

| Saída |
| ----- |

```
X = 19

```

### Exemplo 2

| Entrada |
| ------- |

```
-10
4
```

| Saída |
| ----- |

```
X = -6

```

### Exemplo 3

| Entrada |
| ------- |

```
15
-7
```

| Saída |
| ----- |

```
X = 8

```

# ed-01-acampamento

Nas férias de Julho, várias escolas de uma mesma região resolveram se organizar e levaram uma parte de seus alunos para um acampamento de férias por uma semana. Nestes acampamentos os alunos são divididos em chalés coletivos por gênero e idade, sempre com um supervisor ou supervisora que, além de dormirem com o grupo no chalé, também são responsáveis por criar e executar várias atividades interessantes e animadas, para todas as idades. Dentre as diversas atividades podem-se citar jogos, excursões, Gincana Musical, Gincanas Noturnas, etc.

![Acampamento1](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQEPABVKkSJgmzyz_4yq92L30_VSEdBZw-HKTtTuiddQanTny9Jkg5Ud2XwojduU0rrZWc&usqp=CAU)

No primeiro dia de acampamento, devido à forte chuva, as atividades recreativas ficaram limitadas e as crianças foram levadas para o ginásio de esportes. Foi realizada uma gincana e uma das atividades da mesma consistiu em agrupar as crianças em um círculo (organizado no sentido anti-horário) do qual seriam retiradas uma a uma até que sobrasse apenas uma criança, que seria a vencedora.

No momento em que entra no círculo, cada criança recebe uma pequena ficha que contém um valor de 1 a 500. Depois que o círculo é formado, conta-se, iniciando na criança que está ao lado da primeira que entrou no círculo, o número correspondente à ficha que a primeira detém. A criança onde o número contado cair, deve ser retirada do grupo, e a contagem inicia novamente segundo a ficha da criança que acabou de ser eliminada. Para ficar mais interessante, quando o valor que consta na ficha é par, a contagem é feita no sentido horário e quando o valor que consta na ficha é ímpar, a contagem é feita no sentido anti-horário.

![Acampamento2](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRFGdTUFVH4BmRTAhWPIn_gC8ZBHKHmnagtisFHRbn9vGPcZbv9k_LnoJYImGd3YUQMp8Q&usqp=CAU)

A brincadeira fez muito sucesso e o administrador do acampamento pediu para que sua equipe desenvolva um programa para que no próximo evento ele saiba previamente qual criança irá ser a vencedora de cada grupo, com base nas informações fornecidas.

## Especificações de entrada e saída

### Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém um inteiro **N** (1 ≤ **N** ≤ 100), indicando a quantidade de crianças que farão parte de cada círculo e participarão da brincadeira.

Em seguida, as **N** linhas de cada caso de teste conterão duas informações, o **Nome** e o **Valor** (1 ≤ **Valor** ≤ 500) que consta na ficha de cada criança, separados por um espaço, na ordem de entrada na formação do círculo inicial.

Obs: O **Nome** de cada criança não deverá ultrapassar 30 caracteres e contém apenas letras maiúsculas e minúsculas e o caractere "\_", sem espaços, sem acentos. O final da entrada é indicado pelo número zero.

### Saída

Para cada caso de teste, deve-se apresentar a mensagem Vencedor(a): xxxxxx, com um espaço após o sinal ":" indicando qual é a criança do grupo que venceu a brincadeira.

## Exemplos

### Exemplo 1

| Entrada |
| ------- |

```
3
Fernanda 7
Fernando 9
Gustavo 11
5
Maria 7
Pedro 9
Joao_Vitor 5
Isabel 12
Laura 8
0
```

| Saída |
| ----- |

```
Vencedor(a): Fernanda
Vencedor(a): Pedro

```

### Exemplo 2

| Entrada |
| ------- |

```
3
Maria 4
Pedro 3
Joao 2
0
```

| Saída |
| ----- |

```
Vencedor(a): Pedro

```

## ATENÇÃO

- Você deve implemetar (corretamente) um TAD de listas ligadas.
- O código principal deve ser entregue em um arquivo separado (ex. main.c) do TAD.
- No TAD, a interface e a implementação também devem estar em arquivos separados (ex. nomeTAD.c e nomeTAD.h).
- O Trabalho deverá ser entregue comentado e com a indentação correta.
- Você deve resolver o problema utilizando listas ligadas.
- Para mover os nós da lista, você pode apenas manipular os ponteiros da lista, isto é, não pode criar/remover nós, ou modificar os dados dos nós da lista.
- Você deve alocar (malloc) apenas o espaço necessário para resolver o problema.
- Você deve desalocar (free) todo o espaço alocado dinamicamente.
