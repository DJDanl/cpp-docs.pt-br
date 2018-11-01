---
title: false (C++)
ms.date: 11/04/2016
f1_keywords:
- false_cpp
helpviewer_keywords:
- false keyword [C++]
ms.assetid: cc13aec5-1f02-4d38-8dbf-5473ea2b354f
ms.openlocfilehash: 5fc27c7f1dfde7d1f686f0a752652773ade9cc0e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464058"
---
# <a name="false-c"></a>false (C++)

A palavra-chave é um dos dois valores para uma variável do tipo [bool](../cpp/bool-cpp.md) ou uma expressão condicional (uma expressão condicional agora é um **verdadeiro** expressão booleana). Por exemplo, se `i` é uma variável do tipo **bool**, o `i = false;` instrução atribui **falso** para `i`.

## <a name="example"></a>Exemplo

```cpp
// bool_false.cpp
#include <stdio.h>

int main()
{
    bool bb = true;
    printf_s("%d\n", bb);
    bb = false;
    printf_s("%d\n", bb);
}
```

```Output
1
0
```

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)