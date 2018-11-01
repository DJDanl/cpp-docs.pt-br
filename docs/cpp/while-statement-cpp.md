---
title: Instrução while (C++)
ms.date: 11/04/2016
f1_keywords:
- while_cpp
helpviewer_keywords:
- while keyword [C++]
- while keyword [C++], syntax
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
ms.openlocfilehash: 63a1b4c5433a42edd798926c1b025ab4494b64b7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50608975"
---
# <a name="while-statement-c"></a>Instrução while (C++)

Executa *instrução* repetidamente até que *expressão* for avaliada como zero.

## <a name="syntax"></a>Sintaxe

```
while ( expression )
   statement
```

## <a name="remarks"></a>Comentários

O teste de *expressão* ocorre antes de cada execução do loop; portanto, um **enquanto** loop é executado zero ou mais vezes. *expressão* deve ser de um tipo integral, um tipo de ponteiro, ou um tipo de classe com conversão inequívoca em integral ou tipo de ponteiro.

Um **enquanto** loop também pode terminar quando um [quebra](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), ou [retornar](../cpp/return-statement-cpp.md) dentro da instrução corpo é executado. Use [continue](../cpp/continue-statement-cpp.md) para finalizar a iteração atual sem sair do **enquanto** loop. **Continue** passa para a próxima iteração do controle de **enquanto** loop.

O código a seguir usa uma **enquanto** loop à direita serão cortados sublinhados de uma cadeia de caracteres:

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

## <a name="see-also"></a>Consulte também

[Instruções de iteração](../cpp/iteration-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)<br/>
[Instrução for (C++)](../cpp/for-statement-cpp.md)<br/>
[Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)