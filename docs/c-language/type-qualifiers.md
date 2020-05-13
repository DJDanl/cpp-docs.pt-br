---
title: Qualificadores de tipo
ms.date: 11/04/2016
helpviewer_keywords:
- volatile keyword [C], type qualifier
- type qualifiers
- volatile keyword [C]
- qualifiers for types
- const keyword [C]
- memory, access using volatile
- volatile keyword [C], type specifier
ms.assetid: bb4c6744-1dd7-40a8-b4eb-f5585be30908
ms.openlocfilehash: a5cb7ab3de8938b77dc95be3ee442f71d3b18b42
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62344792"
---
# <a name="type-qualifiers"></a>Qualificadores de tipo

Os qualificadores de tipo fornecem uma de duas propriedades a um identificador. O qualificador de tipo **const** declara um objeto como não modificável. O qualificador de tipo `volatile` declara um item cujo valor possa ser alterado legitimamente para algo além do controle do programa em que aparece como um thread de execução simultânea.

Os dois qualificadores de tipo, **const** e `volatile`, podem aparecer apenas uma vez em uma declaração. Os qualificadores de tipo podem aparecer com qualquer especificador de tipo; porém, eles não podem aparecer depois da primeira vírgula em uma declaração de vários itens. Por exemplo, as seguintes declarações são aceitáveis:

```
typedef volatile int VI;
const int ci;
```

Estas declarações não são aceitáveis:

```
typedef int *i, volatile *vi;
float f, const cf;
```

Os qualificadores de tipo são relevantes apenas ao acessar identificadores como l-values nas expressões. Consulte [Expressões L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md) para obter informações sobre l-values e expressões.

## <a name="syntax"></a>Sintaxe

*type-qualifier*: **constvolatile**

Os exemplos abaixo são declarações **const** e `volatile` aceitáveis:

```
int const *p_ci;       /* Pointer to constant int */
int const (*p_ci);     /* Pointer to constant int */
int *const cp_i;       /* Constant pointer to int */
int (*const cp_i);     /* Constant pointer to int */
int volatile vint;     /* Volatile integer        */
```

Se a especificação de um tipo de matriz incluir qualificadores de tipo, o elemento será qualificada, não o tipo de matriz. Se a especificação de tipo de função incluir qualificadores, o comportamento será indefinido. Nem `volatile` nem **const** afetam o alcance de valores ou propriedades aritméticas do objeto.

Esta lista descreve como usar **const** e `volatile`.

- A palavra-chave **const** pode ser usada para modificar qualquer tipo fundamental ou de agregação, um ponteiro para um objeto de qualquer tipo ou um `typedef`. Se um item for declarado apenas com o qualificador de tipo **const** , seu tipo será levado para ser **const int**. Uma variável **const** pode ser inicializada ou pode ser colocada em uma região somente leitura do armazenamento. A palavra-chave **const** é útil para declarar ponteiros para **const**, pois isso requer que a função não altere o ponteiro de qualquer maneira.

- O compilador pressupõe que, a qualquer momento no programa, uma variável de `volatile` pode ser acessada por um processo desconhecido que usa ou modifica seu valor. Portanto, independentemente das otimizações especificadas na linha de comando, o código para cada atribuição ou referência a uma variável `volatile` deve ser gerado mesmo se isso não tiver qualquer efeito aparente.

   Se `volatile` for usado sozinho, `int` será presumido. O especificador de tipo `volatile` pode ser usado para fornecer acesso confiável aos locais especiais de memória. Use `volatile` com objetos de dados que possam ser acessados ou modificados por manipuladores de sinal, por programas de execução simultânea ou por hardware especial, como registros de controle de E/S mapeadas em memória. Você pode declarar uma variável como `volatile` para seu tempo de vida, ou você pode determinar que uma única referência seja `volatile`.

- Um item pode ser **const** e `volatile` ao mesmo tempo. Nesse caso, ele não pode ser modificado legitimamente por seu próprio programa, mas pode ser modificado por algum processo não simultâneo.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
