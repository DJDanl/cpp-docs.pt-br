---
title: Erro do compilador C2004
ms.date: 11/04/2016
f1_keywords:
- C2004
helpviewer_keywords:
- C2004
ms.assetid: d81526dd-3a00-4593-87b0-d910d3d29bca
ms.openlocfilehash: b781e9f81342f35d66eca222bd338252b739096c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74737485"
---
# <a name="compiler-error-c2004"></a>Erro do compilador C2004

esperado ' defined (ID) '

Um identificador deve aparecer entre parênteses após a palavra-chave de pré-processador.

Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: parênteses ausentes na diretiva de pré-processador. Se o parêntese de fechamento estiver ausente de uma diretiva de pré-processador, o compilador irá gerar um erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2004:

```cpp
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

Resolução possível:

```cpp
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
