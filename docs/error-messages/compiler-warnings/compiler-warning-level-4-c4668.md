---
title: Compilador aviso (nível 4) C4668
ms.date: 11/04/2016
f1_keywords:
- C4668
helpviewer_keywords:
- C4668
ms.assetid: c6585460-bc4a-4a15-9242-4cbfce53c961
ms.openlocfilehash: 11d96941a1efddde87068af8829e24259f2fa312
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408154"
---
# <a name="compiler-warning-level-4-c4668"></a>Compilador aviso (nível 4) C4668

'symbol' não é definido como uma macro de pré-processador, substituindo por '0' para 'directives'

Um símbolo que não foi definido foi usado com uma diretiva de pré-processador. O símbolo será avaliada como falsa. Para definir um símbolo, você pode usar o [#define diretiva](../../preprocessor/hash-define-directive-c-cpp.md) ou [/D](../../build/reference/d-preprocessor-definitions.md) opção de compilador.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4668:

```
// C4668.cpp
// compile with: /W4
#include <stdio.h>

#pragma warning (default : 4668)   // turn warning on

int main()
{
    #if q   // C4668, q is not defined
        printf_s("defined");
    #else
        printf_s("undefined");
    #endif
}
```