---
title: alignof e alignas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 1d18aa8a-9621-4fb5-86e5-4cc86d5187f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 96dd03d8aebb8860d5a16c8d08bb35dd8a7d8b48
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46065797"
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