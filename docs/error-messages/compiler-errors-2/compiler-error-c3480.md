---
title: Erro do compilador C3480
ms.date: 11/04/2016
f1_keywords:
- C3480
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
ms.openlocfilehash: 2ebcce496fd06c30420558d80cc0a0c9318d4376
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173403"
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

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)