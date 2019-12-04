---
title: Erro do compilador C3484
ms.date: 11/04/2016
f1_keywords:
- C3484
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
ms.openlocfilehash: c9895a3e5a8ae7e941fccde2da85fedfb3d2c6dd
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743114"
---
# <a name="compiler-error-c3484"></a>Erro do compilador C3484

'-> ' esperado antes do tipo de retorno

Você deve fornecer `->` antes do tipo de retorno de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Forneça `->` antes do tipo de retorno.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3484:

```cpp
// C3484a.cpp

int main()
{
   return []() . int { return 42; }(); // C3484
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3484 fornecendo `->` antes do tipo de retorno da expressão lambda:

```cpp
// C3484b.cpp

int main()
{
   return []() -> int { return 42; }();
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
