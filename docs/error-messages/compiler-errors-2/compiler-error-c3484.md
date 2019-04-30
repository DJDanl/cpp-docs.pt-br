---
title: Erro do compilador C3484
ms.date: 11/04/2016
f1_keywords:
- C3484
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
ms.openlocfilehash: c4405eb81911b1081d19d25ba779d24bee8f6d37
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62381261"
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

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)