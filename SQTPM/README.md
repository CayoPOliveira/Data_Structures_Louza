# O QUE É O SQTPM?

O SQTPM é um site utilizado pelo professor para envio de trabalhos e correção automática, onde os problemas são no estilo problemas de maratonas de computação, utilizando as estruturas estudadas e desenvolvidas nas aulas é preciso resolver os problemas apresentados. Somente os alunos cadastrados na disciplina tem acesso, portanto aqui são apresentados os problemas desenvolvidos ao longo do semestre em que realizei a matéria.

O sqtpm é um sistema que automatiza a recepção e a verificação da correção de trabalhos de programação. A primeira versão do sqtpm foi colocada no ar em 2004.

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

# ed-02-bacia-hidrografica

![Bacia Hidrográfica](https://sp-ao.shortpixel.ai/client/to_webp,q_glossy,ret_img,w_300/https://www.cobali.org/wp-content/uploads/2016/11/Image-Bassin-versant-300x210.png)

Uma bacia hidrográfica é o conjunto de terras que fazem a drenagem da água das chuvas para um mesmo curso de águas. A formação da bacia é feita através dos desníveis dos terrenos que orientam os cursos da água, sempre das áreas mais altas para as mais baixas. Essa área é limitada por uma linha divisora de águas que a separam duas bacias adjacentes e que pode ser determinada nas cartas topográficas. (Fonte: [Wikipedia](https://pt.wikipedia.org/wiki/Bacia_hidrogr%C3%A1fica))

Geólogos costumam dividir uma área de terras em diferentes regiões com base em sua bacia hidrográfica. Seu trabalho é ajudar nessa tarefa.

## Problema

Dado um mapa de tamanho H por W em que H e W indicam, respectivamente, sua altura e largura, representado por uma matriz M de 2 dimensões com H linhas e W colunas, cada célula M[i,j] armazena um inteiro f que representa a altura do ponto (i,j) no mapa.

O objetivo é rotular o mapa (a matriz) de forma que pontos que pertençam à mesma bacia hidrográfica tenham o mesmo rótulo, observadas as seguintes regras:

- Cada célula M[i,j], possui 4 células vizinhas (com exceção das bordas da matriz que podem ter apenas 2 ou 3) e a visitação da célula M[i,j] a seus vizinhos é feito na ordem: Norte, Oeste, Leste, Sul.
  ou seja:
  - M[i-1,j] → M[i,j-1] → M[i,j+1] → M[i+1,j]

|         | **j-1** | **j**  | **j+1** |
| ------- | ------- | ------ | ------- |
| **i-1** | ---     | 1o     | ---     |
| **i**   | 2o      | M[i,j] | 3o      |
| **i+1** | ---     | 4o     | ---     |

- A partir de cada célula, a água pode fluir (cair) para no máximo uma de suas quatro células vizinhas.

- Caso a célula M[i,j] não possua nenhuma célula vizinha com altura menor que a sua, então a água não flui para nenhuma outra célula, e M[i,j] é chamada de **ponto dissipador**.

- Caso contrário, a água de M[i,j] flui para a célula vizinha de menor altitude.

- Em caso de empate entre células vizinhas a água flui para a célula vizinha que pertence à bacia hidrográfica de menor altitude (caso continue o empate, a água flui para a célula pertencente à bacia de menor rótulo, definido a seguir). <-deve-se considerar a ordem de visitação estipulada em (i)-->

Cada célula que flui diretamente ou indiretamente para o mesmo **ponto dissipador** é parte de uma mesma bacia hidrográfica.

Dessa forma, individualmente cada **ponto dissipador** corresponde a uma bacia diferente.

Cada bacia deve ser rotulada por uma letra minúscula única, tal que, a primeira bacia recebe a letra 'a', a segunda a letra 'b' e assim por diante, até a letra 'z'. A ordem entre as bacias é determinada pela ordem do seu ponto dissipador, que é determinada por sua posição (i, j), considerando primeiro o valor do índice i, e caso haja empate do índice j (ou seja, considere o sentido da matriz de cima para baixo e da esquerda para a direita). Ex: um ponto dissipador M[1,3] é menor do que M[1,4], e M[1,4] é menor que M[2,1].

_Dica:_ Você pode calcular para onde cada ponto de água vai fluir, ou inversamente pensar nos pontos em que a água se acumulará.

## Especificações de entrada e saída

### Entrada

A entrada contém um único caso de teste, a primeira linha contém os dois inteiros H e W (1 ≤ H, W ≤ 100). Em seguida, as próximas H linhas contêm W colunas de inteiros f especificando as altitudes de cada célula M[i,j] (0 ≤ f < 100).

Você pode supor que haverá no máximo 26 bacias hidrográficas em todas as entradas de teste.

### Saída

A saída deve apresentar o mapa com os rótulos das bacias hidrográficas de cada célula.

## Exemplos

### Exemplo 1

| Entrada |
| ------- |

```
3 3
9 6 3
5 9 6
3 5 9
```

| Saída |
| ----- |

```
b a a
b b a
b b b

```

_Note que nesse exemplo os pontos dissipadores estão nos cantos inferior esquerdo e superior direito (M[2,0] e M[0,2]). A água da diagonal flui em direção ao canto inferior esquerdo por causa da altitude menor desse lado (5 versus 6)_

### Exemplo 2

| Entrada |
| ------- |

```
5 5
1 2 3 4 5
2 9 3 9 6
3 3 0 8 7
4 9 8 9 8
5 6 7 8 9
```

| Saída |
| ----- |

```
a a a a a
a a b b a
a b b b a
a b b b a
a a a a a

```

## SUGESTÕES

Utilize o conceito de fila ordenada.

### Fila ordenada

A fila ordenada pode ser vista como uma série de filas simples em que a cada fila é associado um nível. Os clientes são retirados apenas da fila de maior nível. Desta forma, um cliente é atendido:

- antes de todos os clientes de filas de menor nível, mesmo que estes tenham chegado antes dele.
- antes de todos os clientes de sua mesma fila que chegaram após o mesmo.
- Após todos os clientes de filas de maior nível, mesmo que estes tenham chegado após o mesmo

Um algoritmo que implementa uma fila ordenada funciona da seguinte forma:

### Algoritmo

- Enquanto fila ordenada não for vazia { - Um cliente X é retirado da fila ordenada.

- Para cada vizinho Y de X sem rótulo faça:

  - atribua o mesmo rótulo de X a Y na matriz.
  - insira o ponto Y na fila ordenada; o seu valor em M indica seu nível de prioridade na fila ordenada.

  }

### Soluções para o Problema da Linha Divisora de Águas

1. Crie uma fila ordenada com 100 filas, uma para cada possível valor na matriz M.
2. Encontre os pontos dissipadores em M e atribua seus rótulos.
3. Insira cada ponto dissipador na fila correspondente à sua altura.
4. Enquanto a fila ordenada não vazia {
   - Retire o ponto X da fila ordenada.
   - Para cada ponto Y vizinho à X que não está rotulado faça:
     - Insira o ponto Y na fila ordenada (em sua fila correspondente);.
     - Atribua o rótulo do ponto X ao ponto Y;
       }

## ATENÇÃO

- Você deve implemetar (corretamente) um TAD de Pilhas que utiliza outro TAD de Listas Ligadas.

- O código principal deve ser entregue em um arquivo separado (ex. main.c) do TAD.
  No TAD, a interface e a implementação também devem estar em arquivos separados (ex. nomeTAD.c e nomeTAD.h).

- O Trabalho deverá ser entregue comentado e com a indentação correta.

- Todo o acesso aos dados deve ser feito respeitando a política de acesso das Pilhas (LIFO).

- Você deve alocar (malloc) apenas o espaço necessário para resolver o problema.

- Você deve desalocar (free) todo o espaço alocado dinamicamente.
