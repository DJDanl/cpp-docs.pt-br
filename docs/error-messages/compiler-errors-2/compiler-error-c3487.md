---
title: Erro do Compilador C3487
ms.date: 11/04/2016
f1_keywords:
- C3487
helpviewer_keywords:
- C3487
ms.assetid: 39bda474-4418-4a79-98bf-2b22fa92eaaa
ms.openlocfilehash: 7b38755470e3746066711382b2ed471badc8e197
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738434"
---
# <a name="compiler-error-c3487"></a>Erro do Compilador C3487

' tipo de retorno ': todas as expressões de retorno devem ser deduzidas para o mesmo tipo: anteriormente, era ' tipo de retorno '

Um lambda deve especificar seu tipo de retorno, a menos que ele contenha uma única instrução de retorno. Se um lambda contiver várias instruções Return, todas deverão ter o mesmo tipo.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Especifique um tipo de retorno à direita para o lambda. Verifique se todos os retornos do lambda são do mesmo tipo ou se podem ser convertidos implicitamente no tipo de retorno.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3487 porque os tipos de retorno do lambda não coincidem:

```cpp
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
