---
title: Compilador aviso (nível 1) C4138 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4138
dev_langs:
- C++
helpviewer_keywords:
- C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d2e637c73482b1a59034d6a269ea2240445bdef
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46046896"
---
# <a name="compiler-warning-level-1-c4138"></a>Compilador aviso (nível 1) C4138

' * /' encontrado fora de comentário

O delimitador de comentário de fechamento não é precedido por um delimitador de comentário de abertura. O compilador pressupõe um espaço entre o asterisco (<strong>\*</strong>) e uma barra (/).

## <a name="example"></a>Exemplo

```
// C4138a.cpp
// compile with: /W1
int */*comment*/ptr;   // C4138 Ambiguous first delimiter causes warning
int main()
{
}
```

Esse aviso pode ser causado pela tentativa de aninhar comentários.

Esse aviso pode ser resolvido se você comentar seções de código que contêm comentários, coloque o código em um **#if / #endif** bloquear e definir a expressão de controle como zero:

```
// C4138b.cpp
// compile with: /W1
#if 0
int my_variable;   /* Declaration currently not needed */
#endif
int main()
{
}
```