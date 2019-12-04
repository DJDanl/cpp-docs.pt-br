---
title: Erro do compilador C3493
ms.date: 11/04/2016
f1_keywords:
- C3493
helpviewer_keywords:
- C3493
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
ms.openlocfilehash: 178d1221886dc62edd9785d211e2189fa50962f4
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738291"
---
# <a name="compiler-error-c3493"></a>Erro do compilador C3493

' var ' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado

A captura de expressão lambda vazia, `[]`, especifica que a expressão lambda não captura explicitamente ou implicitamente nenhuma variável.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Forneça um modo de captura padrão ou

- Capture explicitamente uma ou mais variáveis.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3493 porque ele modifica uma variável externa, mas especifica a cláusula de captura vazia:

```cpp
// C3493a.cpp

int main()
{
   int m = 55;
   [](int n) { m = n; }(99); // C3493
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3493 especificando by-reference como o modo de captura padrão.

```cpp
// C3493b.cpp

int main()
{
   int m = 55;
   [&](int n) { m = n; }(99);
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
