---
title: Erro do compilador C3532
ms.date: 11/04/2016
f1_keywords:
- C3532
helpviewer_keywords:
- C3532
ms.assetid: 51067853-eda8-4f59-86e8-8924e16d3a95
ms.openlocfilehash: 7b5d1fe61ae08811186e25547ccc3f33e3b0198e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62397387"
---
# <a name="compiler-error-c3532"></a>Erro do compilador C3532

'type': uso incorreto de 'auto'

O tipo indicado não pode ser declarado com o `auto` palavra-chave. Por exemplo, você não pode usar o `auto` palavra-chave para declarar uma matriz ou um método de tipo de retorno.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que a expressão de inicialização gera um tipo válido.

1. Certifique-se de que você não declarar uma matriz ou um tipo de retorno do método.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3532 porque o `auto` palavra-chave não pode declarar um tipo de retorno do método.

```
// C3532a.cpp
// Compile with /Zc:auto
auto f(){}   // C3532
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3532 porque o `auto` palavra-chave não pode declarar uma matriz.

```
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