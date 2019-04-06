---
title: Erro do compilador C3483
ms.date: 11/04/2016
f1_keywords:
- C3483
helpviewer_keywords:
- C3483
ms.assetid: 18b3a2c5-dfc9-4661-9653-08a5798474cf
ms.openlocfilehash: acbe89b5183d0991fb8d4a571a9595d6f6bafc6c
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59026117"
---
# <a name="compiler-error-c3483"></a>Erro do compilador C3483

'var' já é parte da lista de captura de lambda

Você passou a mesma variável para a lista de captura de uma expressão lambda mais de uma vez.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova todas as instâncias adicionais da variável da lista de captura.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3483 porque a variável `n` aparece mais de uma vez na lista da expressão lambda captura:

```
// C3483.cpp

int main()
{
   int m = 6, n = 5;
   [m,n,n] { return n + m; }(); // C3483
}
```

## <a name="see-also"></a>Consulte também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)