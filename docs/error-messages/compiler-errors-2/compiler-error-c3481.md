---
title: Erro do compilador C3481
ms.date: 11/04/2016
f1_keywords:
- C3481
helpviewer_keywords:
- C3481
ms.assetid: 5d09375a-5ed3-4b61-86ed-45e91fd734c7
ms.openlocfilehash: 1719e9f1d3328be083f745498e6f4ad772b0b52a
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755233"
---
# <a name="compiler-error-c3481"></a>Erro do compilador C3481

' var ': variável de captura de lambda não encontrada

O compilador não pôde localizar a definição de uma variável que você passou para a lista de captura de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova a variável da lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3481 porque a variável `n` não está definida:

```cpp
// C3481.cpp

int main()
{
   [n] {}(); // C3481
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
