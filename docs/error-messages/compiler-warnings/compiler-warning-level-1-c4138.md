---
title: Compilador aviso (nível 1) C4138
ms.date: 11/04/2016
f1_keywords:
- C4138
helpviewer_keywords:
- C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
ms.openlocfilehash: 96f8915b9bec166496ca4305d796ce8ef514ca15
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402522"
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