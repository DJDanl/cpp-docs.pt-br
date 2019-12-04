---
title: Erro do compilador C3496
ms.date: 11/04/2016
f1_keywords:
- C3496
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
ms.openlocfilehash: b9542f1904c6797a77c88c88a37aff9348364268
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738174"
---
# <a name="compiler-error-c3496"></a>Erro do compilador C3496

' this ' é sempre capturado pelo valor: ' & ' ignorado

Não é possível capturar o ponteiro de `this` por referência.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Capture o ponteiro de `this` por valor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3496 porque uma referência ao ponteiro `this` aparece na lista de captura de uma expressão lambda:

```cpp
// C3496.cpp
// compile with: /c

class C
{
   void f()
   {
      [&this] {}(); // C3496
   }
};
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
