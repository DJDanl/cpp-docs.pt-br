---
title: Erro do compilador C3480
ms.date: 11/04/2016
f1_keywords:
- C3480
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
ms.openlocfilehash: a2fa1a8b02cf05d332210f359ae3ff33ed7d6e35
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686300"
---
# <a name="compiler-error-c3480"></a>Erro do compilador C3480

' var ': uma variável de captura de lambda deve ser de um escopo de função delimitadora

A variável de captura de lambda não é de um escopo de função delimitadora.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova a variável da lista de captura da expressão lambda.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3480 porque a variável `global` não é de um escopo de função delimitadora:

```cpp
// C3480a.cpp

int global = 0;
int main()
{
   [&global] { global = 5; }(); // C3480
}
```

O exemplo a seguir resolve C3480 removendo a variável `global` da lista de captura da expressão lambda:

```cpp
// C3480b.cpp

int global = 0;
int main()
{
   [] { global = 5; }();
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
