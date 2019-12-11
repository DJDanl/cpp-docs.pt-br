---
title: Aviso do compilador (nível 4) C4668
ms.date: 11/04/2016
f1_keywords:
- C4668
helpviewer_keywords:
- C4668
ms.assetid: c6585460-bc4a-4a15-9242-4cbfce53c961
ms.openlocfilehash: 84834ce0f980502e16a8398d35da85d1a005c9cb
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990556"
---
# <a name="compiler-warning-level-4-c4668"></a>Aviso do compilador (nível 4) C4668

'symbol' não é definido como uma macro de pré-processador, substituindo por '0' para 'directives'

Um símbolo que não foi definido foi usado com uma diretiva de pré-processador. O símbolo será avaliado como false. Para definir um símbolo, você pode usar a [diretiva de #define](../../preprocessor/hash-define-directive-c-cpp.md) ou a opção de compilador [/d](../../build/reference/d-preprocessor-definitions.md) .

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4668:

```cpp
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
