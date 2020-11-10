---
title: Qualificadores de tipo
description: Descreve os qualificadores de tipo para a linguagem C usada no compilador do Microsoft Visual C
ms.date: 11/6/2020
helpviewer_keywords:
- volatile keyword [C], type qualifier
- type qualifiers
- volatile keyword [C]
- qualifiers for types
- const keyword [C]
- memory, access using volatile
- volatile keyword [C], type specifier
ms.assetid: bb4c6744-1dd7-40a8-b4eb-f5585be30908
ms.openlocfilehash: dd36aeb5d142eebbd6e4a339fe6c18925a6fd45a
ms.sourcegitcommit: 3f0c1dcdcce25865d1a1022bcc5b9eec79f69025
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2020
ms.locfileid: "94381604"
---
# <a name="type-qualifiers"></a>Qualificadores de tipo

Os qualificadores de tipo fornecem uma de duas propriedades a um identificador. O **`const`** qualificador de tipo declara um objeto que não poderá ser modificado. O **`volatile`** qualificador de tipo declara um item cujo valor pode ser alterado legitimamente por algo além do controle do programa no qual ele aparece, como um thread executando simultaneamente.

Os qualificadores de tipo,, **`const`** **`restrict`** e **`volatile`** , podem aparecer apenas uma vez em uma declaração. Qualificadores de tipo podem aparecer com qualquer especificador de tipo; no entanto, eles não podem aparecer após a primeira vírgula em uma declaração de vários itens. Por exemplo, as seguintes declarações são aceitáveis:

```c
typedef volatile int VI;
const int ci;
```

Essas declarações não são legais:

```c
typedef int *i, volatile *vi;
float f, const cf;
```

Os qualificadores de tipo são relevantes apenas ao acessar identificadores como l-values nas expressões. Consulte [Expressões L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md) para obter informações sobre l-values e expressões.

## <a name="syntax"></a>Sintaxe

*`type-qualifier`* :\
&emsp;**`const`**\
&emsp;**`restrict`**\
&emsp;**`volatile`**

## <a name="const-and-volatile"></a>`const` e `volatile`

As seguintes são as **`const`** declarações e legais **`volatile`** :

```c
int const *p_ci;      // Pointer to constant int
int const (*p_ci);   // Pointer to constant int
int *const cp_i;     // Constant pointer to int
int (*const cp_i);   // Constant pointer to int
int volatile vint;     // Volatile integer
```

Se a especificação de um tipo de matriz incluir qualificadores de tipo, o elemento será qualificada, não o tipo de matriz. Se a especificação de tipo de função incluir qualificadores, o comportamento será indefinido. **`volatile`** e **`const`** não afetam o intervalo de valores ou Propriedades aritméticas do objeto.

- A **`const`** palavra-chave pode ser usada para modificar qualquer tipo fundamental ou agregado, ou um ponteiro para um objeto de qualquer tipo, ou um **`typedef`** . Se um item for declarado apenas com o **`const`** qualificador de tipo, seu tipo será usado como **const int**. Uma **`const`** variável pode ser inicializada ou pode ser colocada em uma região somente leitura do armazenamento. A **`const`** palavra-chave é útil para declarar ponteiros **`const`** , pois isso requer que a função não altere o ponteiro de forma alguma.

- O compilador pressupõe que, em qualquer ponto do programa, uma **`volatile`** variável pode ser acessada por um processo desconhecido que usa ou modifica seu valor. Independentemente das otimizações especificadas na linha de comando, o código para cada atribuição ou referência de uma **`volatile`** variável deve ser gerado mesmo que pareça não ter efeito.

Se **`volatile`** for usado sozinho, **`int`** será assumido. O **`volatile`** especificador de tipo pode ser usado para fornecer acesso confiável a locais de memória especiais. Use **`volatile`** com objetos de dados que podem ser acessados ou alterados por manipuladores de sinais, executando programas simultaneamente ou por hardware especial, como registros de controle de e/s mapeados pela memória. Você pode declarar uma variável como **`volatile`** por seu tempo de vida, ou você pode converter uma única referência para ser **`volatile`** .

- Um item pode ser **`const`** e **`volatile`** , nesse caso, o item não pôde ser modificado legitimamente por seu próprio programa, mas pode ser modificado por algum processo assíncrono.
 
## `restrict`

O **`restrict`** qualificador de tipo, introduzido em C99, pode ser aplicado a declarações de ponteiro. Ele qualifica o ponteiro, não o que aponta para.

**`restrict`** é uma dica de otimização para o compilador que nenhum outro ponteiro no escopo atual refere-se ao mesmo local de memória. Ou seja, somente o ponteiro ou um valor derivado dele (como o ponteiro + 1) é usado para acessar o objeto durante o tempo de vida do ponteiro. Isso ajuda o compilador a produzir código mais otimizado. C++ tem um mecanismo equivalente, [`__restrict`](../cpp/extension-restrict.md)

Tenha em mente que se trata **`restrict`** de um contrato entre você e o compilador. Se você fizer um alias com um ponteiro marcado com **`restrict`** , o resultado será indefinido.

Veja um exemplo que usa **`restrict`** :

```c
void test(int* restrict first, int* restrict second, int* val)
{
    *first += *val;
    *second += *val;
}

int main()
{
    int i = 1, j = 2, k = 3;
    test(&i, &j, &k);

    return 0;
}

// Marking union members restrict tells the compiler that
// only z.x or z.y will be accessed in any scope, which allows
// the compiler to optimize access to the members.
union z 
{
    int* restrict x;
    double* restrict y;
};
```

## <a name="see-also"></a>Confira também

[`/std` (Especifique a versão padrão do idioma)](../build/reference/std-specify-language-standard-version.md)\
[Declarações e tipos](../c-language/declarations-and-types.md)
