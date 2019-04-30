---
title: Erro do compilador C3485
ms.date: 11/04/2016
f1_keywords:
- C3485
helpviewer_keywords:
- C3485
ms.assetid: d67536f9-67a1-4ad9-9a94-d8bbbca3d0dc
ms.openlocfilehash: 2fcaecd6be35e2ae6822133930b48b6bbf02aafe
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62381131"
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