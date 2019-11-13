---
title: Aviso do compilador (nível 1) C4906
ms.date: 11/04/2016
f1_keywords:
- C4906
helpviewer_keywords:
- C4906
ms.assetid: 05318e74-799b-412a-9dce-f02b8161d762
ms.openlocfilehash: 8ef1798cee93e0896000dd0187222cf675011af9
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74050143"
---
# <a name="compiler-warning-level-1-c4906"></a>Aviso do compilador (nível 1) C4906

literal de cadeia de caracteres convertido em 'LPWSTR'

O compilador detectou uma conversão não segura. A conversão teve sucesso, mas você deve usar uma rotina de conversão.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4906:

```cpp
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