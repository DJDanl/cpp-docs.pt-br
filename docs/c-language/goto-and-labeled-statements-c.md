---
title: Instruções goto e identificadas (C)
ms.date: 11/04/2016
f1_keywords:
- goto
helpviewer_keywords:
- labeled statement
- statements, labeled
- goto keyword [C]
ms.assetid: 3d0473dc-4b18-4fcc-9616-31a38499d7d7
ms.openlocfilehash: d84aa6701ef030dc494f6a40a7223d6f9bcd5073
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87199978"
---
# <a name="goto-and-labeled-statements-c"></a>Instruções goto e identificadas (C)

A **`goto`** instrução transfere o controle para um rótulo. O rótulo fornecido deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função.

## <a name="syntax"></a>Sintaxe

*instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução rotulada*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de salto*

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`goto`**  *identificador*  **;**

*rotulado-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador*  **:**  *instrução*

Um rótulo de instrução é significativo apenas para uma **`goto`** instrução; em qualquer outro contexto, uma instrução rotulada é executada sem considerar o rótulo.

Um elemento *jump-statement* deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função. O conjunto de nomes de *identificadores* a seguir **`goto`** tem seu próprio espaço de nome para que os nomes não interfiram com outros identificadores. Os rótulos não podem ser redeclarados. Consulte [Namespaces](../c-language/name-spaces.md) para obter mais informações.

É um bom estilo de programação usar a **`break`** **`continue`** instrução, e **`return`** em preferência, **`goto`** sempre que possível. Como a **`break`** instrução só sai de um nível do loop, uma **`goto`** pode ser necessária para sair de um loop de dentro de um loop profundamente aninhado.

Este exemplo demonstra a **`goto`** instrução:

```c
// goto.c
#include <stdio.h>

int main()
{
    int i, j;

    for ( i = 0; i < 10; i++ )
    {
        printf_s( "Outer loop executing. i = %d\n", i );
        for ( j = 0; j < 3; j++ )
        {
            printf_s( " Inner loop executing. j = %d\n", j );
            if ( i == 5 )
                goto stop;
        }
    }

    /* This message does not print: */
    printf_s( "Loop exited. i = %d\n", i );

    stop: printf_s( "Jumped to stop. i = %d\n", i );
}
```

Neste exemplo, uma **`goto`** instrução transfere o controle para o ponto rotulado `stop` quando `i` é igual a 5.

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
