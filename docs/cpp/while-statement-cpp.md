---
title: Instrução while (C++)
ms.date: 11/04/2016
f1_keywords:
- while_cpp
helpviewer_keywords:
- while keyword [C++]
- while keyword [C++], syntax
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
ms.openlocfilehash: 168b1fc20d165c44c3230a8d1094c99b689ddbb9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233542"
---
# <a name="while-statement-c"></a>Instrução while (C++)

Executa a *instrução* repetidamente até que a *expressão* seja avaliada como zero.

## <a name="syntax"></a>Sintaxe

```
while ( expression )
   statement
```

## <a name="remarks"></a>Comentários

O teste de *expressão* ocorre antes de cada execução do loop; Portanto, um **`while`** loop é executado zero ou mais vezes. a *expressão* deve ser de um tipo integral, um tipo de ponteiro ou um tipo de classe com uma conversão não ambígua para um tipo integral ou de ponteiro.

Um **`while`** loop também pode terminar quando um [Break](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md)ou [Return](../cpp/return-statement-cpp.md) dentro do corpo da instrução for executado. Use [continuar](../cpp/continue-statement-cpp.md) para encerrar a iteração atual sem sair do **`while`** loop. **`continue`** passa o controle para a próxima iteração do **`while`** loop.

O código a seguir usa um **`while`** loop para cortar sublinhados à direita de uma cadeia de caracteres:

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
[Instrução for com base em intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
