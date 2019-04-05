---
title: Erro do compilador C3484
ms.date: 11/04/2016
f1_keywords:
- C3484
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
ms.openlocfilehash: c4405eb81911b1081d19d25ba779d24bee8f6d37
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039972"
---
# <a name="compiler-error-c3484"></a>Erro do compilador C3484

esperado '->' antes do tipo de retorno

Você deve fornecer `->` antes do tipo de retorno de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Fornecer `->` antes do tipo de retorno.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3484:

```
// C3484a.cpp

int main()
{
   return []() . int { return 42; }(); // C3484
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3484 fornecendo `->` antes do tipo de retorno da expressão lambda:

```
// C3484b.cpp

int main()
{
   return []() -> int { return 42; }();
}
```

## <a name="see-also"></a>Consulte também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)