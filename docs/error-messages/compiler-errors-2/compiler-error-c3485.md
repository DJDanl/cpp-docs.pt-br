---
title: Erro do compilador C3485
ms.date: 11/04/2016
f1_keywords:
- C3485
helpviewer_keywords:
- C3485
ms.assetid: d67536f9-67a1-4ad9-9a94-d8bbbca3d0dc
ms.openlocfilehash: 09080a402767835cda9711c2f0fc4d7c8d787439
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508008"
---
# <a name="compiler-error-c3485"></a>Erro do compilador C3485

uma definição de lambda não pode ter cv-qualifiers

Não é possível usar um `const` ou `volatile` qualificador como parte da definição de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remover o `const` ou `volatile` qualificador da definição da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3485 porque ele usa o `const` qualificador como parte da definição de uma expressão lambda:

```
// C3485.cpp

int main()
{
   auto x = []() const mutable {}; // C3485
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)