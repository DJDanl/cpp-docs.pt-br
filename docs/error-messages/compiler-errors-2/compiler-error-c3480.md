---
title: Erro do compilador C3480
ms.date: 11/04/2016
f1_keywords:
- C3480
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
ms.openlocfilehash: 255fb12d587a94aac798814736f0b26770f608b0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760472"
---
# <a name="compiler-error-c3480"></a>Erro do compilador C3480

' var ': uma variável de captura de lambda deve ser de um escopo de função delimitadora

A variável de captura de lambda não é de um escopo de função delimitadora.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Remova a variável da lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3480 porque a variável `global` não é de um escopo de função delimitadora:

```cpp
// C3480a.cpp

int global = 0;
int main()
{
   [&global] { global = 5; }(); // C3480
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3480 removendo a variável `global` da lista de captura da expressão lambda:

```cpp
// C3480b.cpp

int global = 0;
int main()
{
   [] { global = 5; }();
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
