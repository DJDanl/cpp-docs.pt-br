---
title: Erro do compilador C3496
ms.date: 11/04/2016
f1_keywords:
- C3496
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
ms.openlocfilehash: 993d391f28a59afc8926748f2e6f34ab441657dc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228850"
---
# <a name="compiler-error-c3496"></a>Erro do compilador C3496

' this ' é sempre capturado pelo valor: ' & ' ignorado

Não é possível capturar o **`this`** ponteiro por referência.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Capture o **`this`** ponteiro por valor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3496 porque uma referência ao **`this`** ponteiro aparece na lista de captura de uma expressão lambda:

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

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
