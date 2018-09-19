---
title: Erro do compilador C3487 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3487
dev_langs:
- C++
helpviewer_keywords:
- C3487
ms.assetid: 39bda474-4418-4a79-98bf-2b22fa92eaaa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: acd0dad31a565b9e75741e3a66a5d48dfedec69f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087104"
---
# <a name="compiler-error-c3487"></a>Erro do Compilador C3487

tipo de retorno: todos retornam expressões devem ser deduzidas para o mesmo tipo: anteriormente era 'tipo de retorno'

Um lambda deve especificar seu tipo de retorno, a menos que ele contém uma única instrução return. Se um lambda contém múltiplas instruções de retorno, eles devem todos ter o mesmo tipo.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Especifique um tipo de retorno à direita para o lambda. Verifique se todas as devoluções de lambda são do mesmo tipo ou podem ser convertidas implicitamente para o tipo de retorno.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3487 porque os tipos de retorno do lambda não são compatíveis:

```
// C3487.cpp
// Compile by using: cl /c /W4 C3487.cpp

int* test(int* pi) {
   // To fix the error, uncomment the trailing return type below
   auto odd_pointer = [=]() /* -> int* */ {
      if (*pi % 2)
         return pi;
      return nullptr; // C3487 - nullptr is not an int* type
   };
   return odd_pointer();
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)