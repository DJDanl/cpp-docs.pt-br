---
title: Compilador aviso (nível 4) C4668 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4668
dev_langs:
- C++
helpviewer_keywords:
- C4668
ms.assetid: c6585460-bc4a-4a15-9242-4cbfce53c961
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c960eb2cc79298977c8d7c91808b0a5492d05758
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073987"
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