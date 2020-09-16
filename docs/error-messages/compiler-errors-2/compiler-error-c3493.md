---
title: Erro do compilador C3493
ms.date: 11/04/2016
f1_keywords:
- C3493
helpviewer_keywords:
- C3493
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
ms.openlocfilehash: ea2c1a3d9a10fee455d20490f0408982f47ee0a7
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684723"
---
# <a name="compiler-error-c3493"></a>Erro do compilador C3493

' var ' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado

A captura de expressão lambda vazia, `[]` , especifica que a expressão lambda não captura explicitamente ou implicitamente nenhuma variável.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Forneça um modo de captura padrão ou

- Capture explicitamente uma ou mais variáveis.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3493 porque ele modifica uma variável externa, mas especifica a cláusula de captura vazia:

```cpp
// C3493a.cpp

int main()
{
   int m = 55;
   [](int n) { m = n; }(99); // C3493
}
```

O exemplo a seguir resolve C3493 especificando by-reference como o modo de captura padrão.

```cpp
// C3493b.cpp

int main()
{
   int m = 55;
   [&](int n) { m = n; }(99);
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
