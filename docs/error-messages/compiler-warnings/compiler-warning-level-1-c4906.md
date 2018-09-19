---
title: Compilador aviso (nível 1) C4906 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4906
dev_langs:
- C++
helpviewer_keywords:
- C4906
ms.assetid: 05318e74-799b-412a-9dce-f02b8161d762
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6bdcd726fc8597f1bdaadd2633d6c564b66280f1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46097016"
---
# <a name="compiler-warning-level-1-c4906"></a>Compilador aviso (nível 1) C4906

literal de cadeia de caracteres convertido em 'LPWSTR'

O compilador detectou uma conversão não segura. A conversão foi bem-sucedida, mas você deve usar uma rotina de conversão.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4906:

```
// C4906.cpp
// compile with: /W1
#pragma warning(default : 4906)
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    LPWSTR x = (LPWSTR)"1234";   // C4906

    // try the following lines instead
    // char y[128];
    // size_t numberOfCharConverted = 0;
    // errcode err = 0;
    // err = wcstombs_s(&numberOfCharConverted , &y[0], 128,
    //                  L"12345", 4);
    // if (err != 0)
    // {
    //     printf_s("wcstombs_s failed!");
    //     return -1;
    // }
    // printf_s("%s\n", y);

    return 0;
}
```