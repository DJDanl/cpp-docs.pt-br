---
title: false (C++)
ms.date: 11/04/2016
f1_keywords:
- false_cpp
helpviewer_keywords:
- false keyword [C++]
ms.assetid: cc13aec5-1f02-4d38-8dbf-5473ea2b354f
ms.openlocfilehash: f363e309b91e44472447d040aa36752750afec6f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188929"
---
# <a name="false-c"></a>false (C++)

A palavra-chave é um dos dois valores de uma variável do tipo [bool](../cpp/bool-cpp.md) ou uma expressão condicional (uma expressão condicional é agora uma expressão booliana **verdadeira** ). Por exemplo, se `i` for uma variável do tipo **bool**, a instrução `i = false;` atribuirá **false** a `i`.

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

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
