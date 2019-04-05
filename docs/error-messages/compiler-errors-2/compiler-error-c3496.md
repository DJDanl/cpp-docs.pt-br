---
title: Erro do compilador C3496
ms.date: 11/04/2016
f1_keywords:
- C3496
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
ms.openlocfilehash: 025498f3fe244916cd0a06e36feee6fdb532acc6
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59026680"
---
# <a name="compiler-error-c3496"></a>Erro do compilador C3496

'this' sempre é capturado por valor: '&' ignorado

Não é possível capturar a `this` ponteiro por referência.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Capturar o `this` ponteiro por valor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3496 porque uma referência para o `this` ponteiro aparece na lista de captura de uma expressão lambda:

```
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

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)