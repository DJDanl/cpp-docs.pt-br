---
title: Instrução nula
ms.date: 11/04/2016
helpviewer_keywords:
- expressions [C++], null
- null statement
- null values, expressions
ms.assetid: 606f5953-55f0-40c8-ae03-3ee3a819b851
ms.openlocfilehash: 167a1e579c15fd59da1979efd9aa979184318115
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177801"
---
# <a name="null-statement"></a>Instrução nula

A "instrução NULL" é uma instrução de expressão com a *expressão* ausente. É útil quando a sintaxe da linguagem pede por uma instrução, mas nenhuma avaliação de expressão. Consiste em um ponto e vírgula.

Em geral, as instruções nulas são usadas como espaços reservados em instruções de iteração ou como instruções nas quais são colocados rótulos no final de instruções ou funções compostas.

O seguinte fragmento de código mostra como copiar uma cadeia de caracteres para outra e incorpora a instrução nula:

```cpp
// null_statement.cpp
char *myStrCpy( char *Dest, const char *Source )
{
    char *DestStart = Dest;

    // Assign value pointed to by Source to
    // Dest until the end-of-string 0 is
    // encountered.
    while( *Dest++ = *Source++ )
        ;   // Null statement.

    return DestStart;
}

int main()
{
}
```

## <a name="see-also"></a>Confira também

[Instrução de expressão](../cpp/expression-statement.md)
