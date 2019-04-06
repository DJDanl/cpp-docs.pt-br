---
title: Erro do compilador C3480
ms.date: 11/04/2016
f1_keywords:
- C3480
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
ms.openlocfilehash: 2ebcce496fd06c30420558d80cc0a0c9318d4376
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038988"
---
# <a name="compiler-error-c3480"></a>Erro do compilador C3480

'var': uma variável de captura de lambda deve ser de um escopo delimitador de função

A variável de captura de lambda não é de um escopo delimitador da função.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova a variável na lista da expressão lambda captura.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3480 porque a variável `global` não é de um escopo delimitador de função:

```
// C3480a.cpp

int global = 0;
int main()
{
   [&global] { global = 5; }(); // C3480
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3480, removendo a variável `global` da lista de captura da expressão lambda:

```
// C3480b.cpp

int global = 0;
int main()
{
   [] { global = 5; }();
}
```

## <a name="see-also"></a>Consulte também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)