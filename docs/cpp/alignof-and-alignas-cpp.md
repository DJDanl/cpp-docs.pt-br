---
title: alignof e alignas (C++)
ms.date: 11/04/2016
ms.assetid: 1d18aa8a-9621-4fb5-86e5-4cc86d5187f4
ms.openlocfilehash: e5d023d7969764bdd36030a508abdd94068e48b5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50493646"
---
# <a name="alignof-and-alignas-c"></a>alignof e alignas (C++)

O **alignas** especificador de tipo é uma maneira padrão de C++ portáteis, para especificar um alinhamento personalizado de variáveis e tipos definidos pelo usuário. O **alignof** operador da mesma forma é uma maneira padrão e portátil para obter o alinhamento de uma variável ou um tipo especificado.

## <a name="example"></a>Exemplo

Você pode usar **alignas** em uma classe, ignorada ou união, ou em membros individuais. Quando vários **alignas** especificadores forem encontrados, o compilador escolherá aquela mais rígida, (aquele com o maior valor).

```cpp
// alignas_alignof.cpp
// compile with: cl /EHsc alignas_alignof.cpp
#include <iostream>

struct alignas(16) Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes
    alignas(4) char arr[3];
    short s;          // 2 bytes
};

int main()
{
    std::cout << alignof(Bar) << std::endl; // output: 16
}
```

## <a name="see-also"></a>Consulte também

[Alinhamento](../cpp/alignment-cpp-declarations.md)