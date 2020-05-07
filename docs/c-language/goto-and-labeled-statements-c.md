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
ms.openlocfilehash: b5e0d602332c87510b1fe5f59db3e497b88f0acb
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75299111"
---
# <a name="goto-and-labeled-statements-c"></a>Instruções goto e identificadas (C)

A instrução `goto` transfere o controle para um rótulo. O rótulo fornecido deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função.

## <a name="syntax"></a>Sintaxe

*instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução rotulada*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de salto*

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**goto***identificador*GoTo **;**    

*rotulado-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador*  **:**  *instrução*

O rótulo de uma instrução é significante somente para uma instrução `goto`; em qualquer outro contexto, uma instrução rotulada é executada sem considerar o rótulo.

Um elemento *jump-statement* deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função. O conjunto de nomes *identifier* que segue `goto` tem seu próprio namespace para que os nomes não interfiram com outros identificadores. Os rótulos não podem ser redeclarados. Consulte [Namespaces](../c-language/name-spaces.md) para obter mais informações.

É um bom estilo de programação para usar as instruções **break**, **continue** e `return` em vez de `goto` sempre que possível. Como a instrução **break** sai apenas de um nível do loop, um `goto` pode ser necessário para sair de um loop dentro de um loop profundamente aninhado.

Este exemplo demonstra a instrução `goto`:

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

Neste exemplo, uma instrução `goto` transfere o controle para o ponto rotulado `stop` quando o valor de `i` é igual a 5.

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
