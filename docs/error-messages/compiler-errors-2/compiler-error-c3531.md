---
title: Erro do compilador C3531
ms.date: 11/04/2016
f1_keywords:
- C3531
helpviewer_keywords:
- C3531
ms.assetid: 2bdb9fdc-9ddf-403e-8b92-02763d434487
ms.openlocfilehash: 4537c6c76814f2aeb8f8d62579caec86785de252
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91510141"
---
# <a name="compiler-error-c3531"></a>Erro do compilador C3531

' Symbol ': um símbolo cujo tipo contém ' auto ' deve ter um inicializador

A variável especificada não tem uma expressão de inicializador.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Especifique uma expressão de inicializador, como uma atribuição simples que usa a sintaxe de sinal de igual, quando você declara a variável.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3531 porque as variáveis `x1` , `y1, y2, y3` e `z2` não são inicializadas.

```cpp
// C3531.cpp
// Compile with /Zc:auto
int main()
{
   auto x1;                  // C3531
   auto y1, y2, y3;          // C3531
   auto z1 = 1, z2, z3 = -1; // C3531
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-cpp.md)
