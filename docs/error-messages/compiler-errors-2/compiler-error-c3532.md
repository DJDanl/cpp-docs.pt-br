---
title: Erro do compilador C3532
ms.date: 11/04/2016
f1_keywords:
- C3532
helpviewer_keywords:
- C3532
ms.assetid: 51067853-eda8-4f59-86e8-8924e16d3a95
ms.openlocfilehash: 2ef5eb3c2bedd9defbd0b80e6d8c5c8912fcf16d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761927"
---
# <a name="compiler-error-c3532"></a>Erro do compilador C3532

' type ': uso incorreto de ' auto '

O tipo indicado não pode ser declarado com a palavra-chave `auto`. Por exemplo, você não pode usar a palavra-chave `auto` para declarar uma matriz ou um tipo de retorno de método.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se a expressão de inicialização produz um tipo válido.

1. Certifique-se de não declarar uma matriz ou um tipo de retorno de método.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3532 porque a palavra-chave `auto` não pode declarar um tipo de retorno de método.

```cpp
// C3532a.cpp
// Compile with /Zc:auto
auto f(){}   // C3532
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3532 porque a palavra-chave `auto` não pode declarar uma matriz.

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

[Palavra-chave auto](../../cpp/auto-keyword.md)
