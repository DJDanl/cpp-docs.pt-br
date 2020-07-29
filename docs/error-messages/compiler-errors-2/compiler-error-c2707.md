---
title: Erro do compilador C2707
ms.date: 11/04/2016
f1_keywords:
- C2707
helpviewer_keywords:
- C2707
ms.assetid: 3deaf45c-74da-4c9d-acc6-b82412720b74
ms.openlocfilehash: eaac568387138450577ead23f1470c37ad300335
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225417"
---
# <a name="compiler-error-c2707"></a>Erro do compilador C2707

' identifier ': contexto inadequado para função intrínseca

Intrínsecos de manipulação de exceção estruturados são inválidos em determinados contextos:

- `_exception_code()`fora de um filtro de exceção ou **`__except`** bloco

- `_exception_info()`fora de um filtro de exceção

- `_abnormal_termination()`fora de um **`__finally`** bloco

Para resolver o erro, certifique-se de que os intrínsecos de manipulação de exceções sejam colocados no contexto apropriado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2707.

```cpp
// C2707.cpp
#include <windows.h>
#include <stdio.h>

LONG MyFilter(LONG excode)
{
    return (excode == EXCEPTION_ACCESS_VIOLATION ?
        EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH);   // OK
}

LONG func(void)
{
    int x, y;
    return(GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ?  // C2707
             EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH);

    __try
    {
        y = 0;
        x = 4 / y;
        return 0;
     }

    __except(MyFilter(GetExceptionCode()))
    {
        return(GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? // ok
               EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH);
    }
}

int main()
{
    __try
    {
        func();
    } __except(EXCEPTION_EXECUTE_HANDLER)
    {
        printf_s("Caught exception\n");
    }
}
```
