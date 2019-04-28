---
title: Erro do compilador C2004
ms.date: 11/04/2016
f1_keywords:
- C2004
helpviewer_keywords:
- C2004
ms.assetid: d81526dd-3a00-4593-87b0-d910d3d29bca
ms.openlocfilehash: fb100d977188cd3a7d5b0ebbb3e29b53942871dc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208939"
---
# <a name="compiler-error-c2004"></a>Erro do compilador C2004

esperado 'defined (ID)'

Um identificador deve aparecer nos parênteses após a palavra-chave de pré-processador.

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: parênteses ausentes em diretiva de pré-processador. Se faltar o parêntese de fechamento de uma diretiva de pré-processador, o compilador gerará um erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2004:

```
// C2004.cpp
// compile with: /DDEBUG
#include <stdio.h>

int main()
{
    #if defined(DEBUG   // C2004
        printf_s("DEBUG defined\n");
    #endif
}
```

## <a name="example"></a>Exemplo

Solução possível:

```
// C2004b.cpp
// compile with: /DDEBUG
#include <stdio.h>

int main()
{
    #if defined(DEBUG)
        printf_s("DEBUG defined\n");
    #endif
}
```