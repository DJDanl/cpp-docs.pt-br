---
title: Erro do compilador C3484
ms.date: 11/04/2016
f1_keywords:
- C3484
helpviewer_keywords:
- C3484
ms.assetid: 2fe847fa-f6ee-4978-bc1d-b6dc6ae906ac
ms.openlocfilehash: ded4a183f69e4903afb4c9dfeae22f7751ef76ad
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686274"
---
# <a name="compiler-error-c3484"></a>Erro do compilador C3484

'-> ' esperado antes do tipo de retorno

Você deve fornecer `->` antes do tipo de retorno de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Forneça `->` antes do tipo de retorno.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3484:

```cpp
// C3484a.cpp

int main()
{
   return []() . int { return 42; }(); // C3484
}
```

O exemplo a seguir resolve C3484 fornecendo `->` antes o tipo de retorno da expressão lambda:

```cpp
// C3484b.cpp

int main()
{
   return []() -> int { return 42; }();
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
