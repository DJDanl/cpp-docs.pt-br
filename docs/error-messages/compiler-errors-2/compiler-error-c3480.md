---
title: Erro do compilador C3480 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3480
dev_langs:
- C++
helpviewer_keywords:
- C3480
ms.assetid: 7b2e055a-9604-4d13-861b-b38bda1a6940
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1fd58a8c38ee6dc5f77ef280ba3b7a546a666cd6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46107841"
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