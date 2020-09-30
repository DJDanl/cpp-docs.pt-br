---
title: Erro do compilador C3532
ms.date: 11/04/2016
f1_keywords:
- C3532
helpviewer_keywords:
- C3532
ms.assetid: 51067853-eda8-4f59-86e8-8924e16d3a95
ms.openlocfilehash: b8d516074b79704b10d27dd4638585a5ada08323
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91510123"
---
# <a name="compiler-error-c3532"></a>Erro do compilador C3532

' type ': uso incorreto de ' auto '

O tipo indicado não pode ser declarado com a **`auto`** palavra-chave. Por exemplo, você não pode usar a **`auto`** palavra-chave para declarar uma matriz ou um tipo de retorno de método.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se a expressão de inicialização produz um tipo válido.

1. Certifique-se de não declarar uma matriz ou um tipo de retorno de método.

## <a name="examples"></a>Exemplos

O exemplo a seguir produz C3532 porque a **`auto`** palavra-chave não pode declarar um tipo de retorno de método.

```cpp
// C3532a.cpp
// Compile with /Zc:auto
auto f(){}   // C3532
```

O exemplo a seguir produz C3532 porque a **`auto`** palavra-chave não pode declarar uma matriz.

```cpp
// C3532b.cpp
// Compile with /Zc:auto
int main()
{
   int x[5];
   auto a[5];            // C3532
   auto b[1][2];         // C3532
   auto y[5] = x;        // C3532
   auto z[] = {1, 2, 3}; // C3532
   auto w[] = x;         // C3532
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-cpp.md)
