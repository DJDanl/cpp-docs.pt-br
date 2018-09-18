---
title: Erro do compilador C3496 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3496
dev_langs:
- C++
helpviewer_keywords:
- C3496
ms.assetid: e19885f2-677f-4c1e-bc69-e35852262dc3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ec4602e6a0061f5eb750ab29587209a6c97985d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062287"
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

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)