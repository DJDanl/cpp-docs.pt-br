---
title: Instrução while (C++)
ms.date: 11/04/2016
f1_keywords:
- while_cpp
helpviewer_keywords:
- while keyword [C++]
- while keyword [C++], syntax
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
ms.openlocfilehash: 0dfbbb2865c9cf0a23b04ce213a0e739e29c27da
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187317"
---
# <a name="while-statement-c"></a>Instrução while (C++)

Executa a *instrução* repetidamente até que a *expressão* seja avaliada como zero.

## <a name="syntax"></a>Sintaxe

```
while ( expression )
   statement
```

## <a name="remarks"></a>Comentários

O teste de *expressão* ocorre antes de cada execução do loop; Portanto, um loop **while** é executado zero ou mais vezes. a *expressão* deve ser de um tipo integral, um tipo de ponteiro ou um tipo de classe com uma conversão não ambígua para um tipo integral ou de ponteiro.

Um loop **while** também pode terminar quando um [Break](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md)ou [Return](../cpp/return-statement-cpp.md) dentro do corpo da instrução é executado. Use [continuar](../cpp/continue-statement-cpp.md) para encerrar a iteração atual sem sair do loop **while** . **continuar** passa o controle para a próxima iteração do loop **while** .

O código a seguir usa um loop **while** para cortar sublinhados à direita de uma cadeia de caracteres:

```cpp
// while_statement.cpp

#include <string.h>
#include <stdio.h>
char *trim( char *szSource )
{
    char *pszEOS = 0;

    //  Set pointer to character before terminating NULL
    pszEOS = szSource + strlen( szSource ) - 1;

    //  iterate backwards until non '_' is found
    while( (pszEOS >= szSource) && (*pszEOS == '_') )
        *pszEOS-- = '\0';

    return szSource;
}
int main()
{
    char szbuf[] = "12345_____";

    printf_s("\nBefore trim: %s", szbuf);
    printf_s("\nAfter trim: %s\n", trim(szbuf));
}
```

A condição de término é avaliada na parte superior do loop. Se não houver um sublinhado à direita, o loop nunca será executado.

## <a name="see-also"></a>Confira também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for (C++)](../cpp/for-statement-cpp.md)<br/>
[Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
