---
title: Formas obsoletas de declarações e definições da função
ms.date: 11/04/2016
helpviewer_keywords:
- old style function declarations
ms.assetid: 67c5038f-0529-4f29-9d0f-c27580977b50
ms.openlocfilehash: f26e79a586ea451cc51b339b5be593c2359e1f1a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745876"
---
# <a name="obsolete-forms-of-function-declarations-and-definitions"></a>Formas obsoletas de declarações e definições da função

As declarações e definições de função de estilo antigo usam regras ligeiramente diferentes para declarar parâmetros em relação à sintaxe recomendada pelo padrão ANSI C. Primeiro, as declarações de estilo antigo não têm uma lista de parâmetros. Segundo, na definição de função, os parâmetros são listados, mas seus tipos não são declarados na lista de parâmetros. As declarações de tipo precedem a instrução composta que constitui o corpo da função. A sintaxe de estilo antigo está obsoleta e não deve ser usada em novas instâncias de código. Contudo, o código que usa a sintaxe de estilo antigo ainda tem suporte. Este exemplo ilustra os formatos obsoletos de declarações e definições:

```
double old_style();           /* Obsolete function declaration */

double alt_style( a , real )  /* Obsolete function definition */
    double *real;
    int a;
{
    return ( *real + a ) ;
}
```

As funções que retornam um inteiro ou um ponteiro com o mesmo tamanho de um `int` não precisam ter uma declaração, embora ela seja recomendada.

Para manter a conformidade com o padrão ANSI C, as declarações de função de estilo antigo que usam reticências agora geram um erro ao compilar com a opção /Za e um aviso de nível 4 ao compilar com /Ze. Por exemplo:

```cpp
void funct1( a, ... )  /* Generates a warning under /Ze or */
int a;                 /* an error when compiling with /Za */
{
}
```

Recomenda-se reescrever essa declaração como um protótipo:

```cpp
void funct1( int a, ... )
{
}
```

As declarações de função de estilo antigo também geram avisos se você subsequentemente declara ou define a mesma função com reticências ou com um parâmetro de um tipo que não é igual ao tipo promovido.

A próxima seção, [Definições da função C](../c-language/c-function-definitions.md), mostra a sintaxe para definições da função, inclusive a sintaxe de estilo antigo. O não terminal para a lista de parâmetros na sintaxe de estilo antigo é *identifier-list*.

## <a name="see-also"></a>Confira também

[Visão geral das funções](../c-language/overview-of-functions.md)
