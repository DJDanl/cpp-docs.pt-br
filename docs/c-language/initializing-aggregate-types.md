---
title: Inicializando tipos agregados
ms.date: 11/04/2016
helpviewer_keywords:
- aggregate types [C++]
- union keyword [C], declarations
- types [C], initializing
- union keyword [C]
- aggregates [C++], initializing
ms.assetid: a8f8ed75-39db-4592-93b9-d3920d915810
ms.openlocfilehash: b4b0dd82263781966760b6e21ef24ded56b06a01
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229617"
---
# <a name="initializing-aggregate-types"></a>Inicializando tipos agregados

Um tipo de *agregação* é um tipo de estrutura, união ou matriz. Se um tipo de agregação contém membros de tipos de agregação, as regras de inicialização são aplicadas recursivamente.

## <a name="syntax"></a>Sintaxe

*inicializador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{**  *inicializador-lista*  **}** /* para inicialização de agregação\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{**  *inicializador-lista*  **,}**

*initializer-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*initializer*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inicializador-lista*  **,**  *inicializador*

A *initializer-list* é uma lista de inicializadores separados por vírgulas. Cada inicializador na lista é uma expressão constante ou uma lista de inicializadores. Em virtude disso, as listas de inicializadores podem ser aninhadas. Esse formato é útil para inicializar membros de agregações de um tipo de agregação, como mostrado nos exemplos desta seção. No entanto, se o inicializador de um identificador automático for uma expressão única, ele não precisa ser uma expressão constante, apenas ter o tipo apropriado para a atribuição ao identificador.

Para cada lista de inicializadores, os valores das expressões constantes são atribuídos, em ordem, aos membros correspondentes da variável de agregação.

Se *initializer-list* tiver menos valores do que um tipo de agregação, os membros ou os elementos restantes do tipo de agregação serão inicializados como 0. O valor inicial de um identificador automático não inicializado explicitamente será indefinido. Se *initializer-list* tiver mais valores do que um tipo de agregação, ocorrerá um erro. Essas regras se aplicam a cada lista de inicializadores inserida, bem como à agregação como um todo.

O inicializador de uma estrutura é uma expressão do mesmo tipo ou uma lista de inicializadores para seus membros incluídos entre chaves (**{ }**). Os membros sem nome de campo de bits não são inicializados.

Quando uma união é inicializada, *initializer-list* deve ser uma expressão constante única. O valor da expressão constante é atribuído ao primeiro membro de união.

Se o tamanho de uma matriz for desconhecido, o número de inicializadores determina o tamanho da matriz, e seu tipo se torna completo. Não há nenhuma maneira de especificar a repetição de um inicializador em C, ou de inicializar um elemento no meio de uma matriz sem fornecer também todos os valores acima. Se você precisar dessa operação em seu programa, escreva a rotina na linguagem Assembly.

Observe que o número de inicializadores pode definir o tamanho da matriz:

```C
int x[ ] = { 0, 1, 2 }
```

No entanto, se você especificar o tamanho e fornecer o número incorreto de inicializadores, o compilador gerará um erro.

**Específico da Microsoft**

O tamanho máximo para uma matriz é definido por **size_t**. Definido no arquivo de cabeçalho STDDEF. H, **size_t** é um **`unsigned int`** com o intervalo 0x00000000 a 0x7CFFFFFF.

**FINAL específico da Microsoft**

## <a name="examples"></a>Exemplos

Este exemplo mostra inicializadores para uma matriz.

```C
int P[4][3] =
{
    { 1, 1, 1 },
    { 2, 2, 2 },
    { 3, 3, 3,},
    { 4, 4, 4,},
};
```

Essa instrução declara `P` como uma matriz quatro-por-três e inicializa os elementos da primeira linha como 1, os elementos da sua segunda linha como 2, e assim por diante até a quarta linha. Observe que a lista de inicializadores para a terceira e a quarta linhas contém vírgulas depois da última expressão constante. A última lista de inicializadores (`{4, 4, 4,},`) também é seguida por uma vírgula. Essas vírgulas adicionais são permitidas, mas não são obrigatórias. Somente vírgulas que separam expressões constantes e listas de inicializadores são necessárias.

Se um membro de agregação não tiver qualquer lista de inicializadores inserida, os valores serão simplesmente atribuídos, em ordem, a cada membro da subagregação. Portanto, a inicialização no exemplo anterior equivale ao seguinte:

```C
int P[4][3] =
{
   1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4
};
```

As chaves também podem delimitar inicializadores individuais na lista e ajudam a esclarecer o exemplo anterior.

Quando você inicializar uma variável de agregação, deve ter cuidado para usar corretamente as chaves e as listas de inicializadores. O exemplo a seguir ilustra com mais detalhes a interpretação das chaves pelo compilador:

```C
typedef struct
{
    int n1, n2, n3;
} triplet;

triplet nlist[2][3] =
{
    { {  1, 2, 3 }, {  4, 5, 6 }, {  7, 8, 9 } },  /* Row 1 */
    { { 10,11,12 }, { 13,14,15 }, { 16,17,18 } }   /* Row 2 */
};
```

Neste exemplo, `nlist` é declarado como uma matriz de estruturas 2-por-3, cada estrutura com três membros. A linha 1 da inicialização atribui valores à primeira linha de `nlist`, como segue:

1. A primeira chave à esquerda na linha 1 sinaliza ao compilador que a inicialização do primeiro membro da agregação de `nlist` (isto é, `nlist[0]`) foi iniciada.

1. A segunda chave à esquerda indica a inicialização do primeiro membro da agregação de `nlist[0]` (isto é, a estrutura em `nlist[0][0]`) foi iniciada.

1. A primeira chave à direita termina a inicialização da estrutura `nlist[0][0]`; a chave à esquerda a seguir inicia a inicialização de `nlist[0][1]`.

1. O processo continua até o final da linha, onde a chave de fechamento à direita encerra a inicialização de `nlist[0]`.

A linha 2 atribui valores à segunda linha de `nlist` de forma semelhante. Observe que os conjuntos de chaves externos que delimitam os inicializadores nas linhas 1 e 2 são obrigatórios. A construção a seguir, que omite as chaves externas, provocará um erro:

```C
triplet nlist[2][3] =  /* THIS CAUSES AN ERROR */
{
     {  1, 2, 3 },{  4, 5, 6 },{  7, 8, 9 },   /* Line 1 */
     { 10,11,12 },{ 13,14,15 },{ 16,17,18 }    /* Line 2 */
};
```

Nessa construção, a primeira chave deixada na linha 1 inicia a inicialização de `nlist[0]`, que é uma matriz de três estruturas. Os valores 1, 2 e 3, são atribuídos aos três membros da primeira estrutura. Quando a chave à direita seguinte é encontrada (após o valor 3), a inicialização de `nlist[0]` está concluída, e as duas estruturas restantes na matriz de três estruturas são iniciadas automaticamente como 0. Da mesma forma, `{ 4,5,6 }` inicializa a primeira estrutura na segunda linha de `nlist`. As duas estruturas de `nlist[1]` restantes são definidas como 0. Quando o compilador localizar a lista de inicializadores seguinte ( `{ 7,8,9 }` ), ele tentará inicializar `nlist[2]`. Como a `nlist` tem apenas duas linhas, essa tentativa causará um erro.

Neste próximo exemplo, os três **`int`** membros de `x` são inicializados como 1, 2 e 3, respectivamente.

```C
struct list
{
    int i, j, k;
    float m[2][3];
} x = {
        1,
        2,
        3,
       {4.0, 4.0, 4.0}
      };
```

Na estrutura `list` acima, os três elementos na primeira linha de `m` são inicializados em 4.0; os elementos da linha restante de `m` são inicializados em 0.0 por padrão.

```C
union
{
    char x[2][3];
    int i, j, k;
} y = { {
            {'1'},
            {'4'}
        }
      };
```

A variável de união `y`, neste exemplo, é inicializada. O primeiro elemento da união é uma matriz, assim, o inicializador é um inicializador de agregação. A lista de inicializadores `{'1'}` atribui valores para a primeira linha da matriz. Como apenas um valor aparece na lista, o elemento na primeira coluna é inicializado com o caractere `1`, e os dois elementos restantes na linha são inicializados com o valor 0 por padrão. Da mesma forma, o primeiro elemento da segunda linha de `x` é inicializado com o caractere `4`, e os dois elementos restantes na linha são inicializados com o valor 0.

## <a name="see-also"></a>Confira também

[Initialization](../c-language/initialization.md)
