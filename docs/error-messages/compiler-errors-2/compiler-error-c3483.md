---
title: Erro do compilador C3483
ms.date: 11/04/2016
f1_keywords:
- C3483
helpviewer_keywords:
- C3483
ms.assetid: 18b3a2c5-dfc9-4661-9653-08a5798474cf
ms.openlocfilehash: 0d6c1467575e7fae7d5e4862f36e733a68210f8e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74743088"
---
# <a name="compiler-error-c3483"></a>Erro do compilador C3483

' var ' já faz parte da lista de captura de lambda

Você passou a mesma variável para a lista de captura de uma expressão lambda mais de uma vez.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova todas as instâncias adicionais da variável da lista de captura.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3483 porque a variável `n` aparece mais de uma vez na lista de captura da expressão lambda:

```cpp
// C3483.cpp

int main()
{
   int m = 6, n = 5;
   [m,n,n] { return n + m; }(); // C3483
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
