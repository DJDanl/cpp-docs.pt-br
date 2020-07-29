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
ms.openlocfilehash: 729e9f65fd1054b8381f45b81e5276846145ebc1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87198717"
---
# <a name="type-qualifiers"></a>Qualificadores de tipo

Os qualificadores de tipo fornecem uma de duas propriedades a um identificador. O **`const`** qualificador de tipo declara um objeto que não poderá ser modificado. O **`volatile`** qualificador de tipo declara um item cujo valor pode ser alterado legitimamente por algo além do controle do programa no qual ele aparece, como um thread executando simultaneamente.

Os dois qualificadores de tipo **`const`** e **`volatile`** podem aparecer apenas uma vez em uma declaração. Os qualificadores de tipo podem aparecer com qualquer especificador de tipo; porém, eles não podem aparecer depois da primeira vírgula em uma declaração de vários itens. Por exemplo, as seguintes declarações são aceitáveis:

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

As seguintes são as **`const`** declarações e legais **`volatile`** :

```
int const *p_ci;       /* Pointer to constant int */
int const (*p_ci);     /* Pointer to constant int */
int *const cp_i;       /* Constant pointer to int */
int (*const cp_i);     /* Constant pointer to int */
int volatile vint;     /* Volatile integer        */
```

Se a especificação de um tipo de matriz incluir qualificadores de tipo, o elemento será qualificada, não o tipo de matriz. Se a especificação de tipo de função incluir qualificadores, o comportamento será indefinido. Nem **`volatile`** **`const`** afeta o intervalo de valores ou Propriedades aritméticas do objeto.

Esta lista descreve como usar o **`const`** e o **`volatile`** .

- A **`const`** palavra-chave pode ser usada para modificar qualquer tipo fundamental ou agregado, ou um ponteiro para um objeto de qualquer tipo, ou um **`typedef`** . Se um item for declarado apenas com o **`const`** qualificador de tipo, seu tipo será usado como **const int**. Uma **`const`** variável pode ser inicializada ou pode ser colocada em uma região somente leitura do armazenamento. A **`const`** palavra-chave é útil para declarar ponteiros **`const`** , pois isso requer que a função não altere o ponteiro de forma alguma.

- O compilador pressupõe que, em qualquer ponto do programa, uma **`volatile`** variável pode ser acessada por um processo desconhecido que usa ou modifica seu valor. Portanto, independentemente das otimizações especificadas na linha de comando, o código para cada atribuição ou referência de uma **`volatile`** variável deve ser gerado mesmo que pareça não ter nenhum efeito.

   Se **`volatile`** for usado sozinho, **`int`** será assumido. O **`volatile`** especificador de tipo pode ser usado para fornecer acesso confiável a locais de memória especiais. Use **`volatile`** com objetos de dados que podem ser acessados ou alterados por manipuladores de sinais, executando programas simultaneamente ou por hardware especial, como registros de controle de e/s mapeados pela memória. Você pode declarar uma variável como **`volatile`** por seu tempo de vida, ou você pode converter uma única referência para ser **`volatile`** .

- Um item pode ser ambos **`const`** e **`volatile`** , nesse caso, o item não pode ser modificado de forma legítima por seu próprio programa, mas pode ser modificado por algum processo assíncrono.

## <a name="see-also"></a>Confira também

[Declarações e tipos](../c-language/declarations-and-types.md)
