---
title: true (C++)
ms.date: 11/04/2016
f1_keywords:
- true_cpp
helpviewer_keywords:
- true keyword [C++]
ms.assetid: 96be2a70-51c3-4250-9752-874d25a5a11e
ms.openlocfilehash: 5cfc99f446499201a0f54c8e5b1dcc2d7152445c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404696"
---
# <a name="true-c"></a>true (C++)

## <a name="syntax"></a>Sintaxe

```
bool-identifier = true ;
bool-expression logical-operator true ;
```

## <a name="remarks"></a>Comentários

Essa palavra-chave é um dos dois valores para uma variável do tipo [bool](../cpp/bool-cpp.md) ou uma expressão condicional (uma expressão condicional agora é uma expressão booliana true). Se `i` é do tipo **bool**, em seguida, a instrução `i = true;` atribui **verdadeiro** para `i`.

## <a name="example"></a>Exemplo

```cpp
// bool_true.cpp
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