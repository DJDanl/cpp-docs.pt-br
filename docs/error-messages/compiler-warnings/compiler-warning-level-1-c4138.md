---
title: Aviso do compilador (nível 1) C4138
ms.date: 11/04/2016
f1_keywords:
- C4138
helpviewer_keywords:
- C4138
ms.assetid: 65ebf929-bba0-4237-923b-c1b66adfe17d
ms.openlocfilehash: e6e368f27371b744efa4006630938f68f51a2ca0
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627103"
---
# <a name="compiler-warning-level-1-c4138"></a>Aviso do compilador (nível 1) C4138

' */' encontrado fora do comentário

O delimitador de comentário de fechamento não é precedido por um delimitador de comentário de abertura. O compilador assume um espaço entre o asterisco (<strong>\*</strong>) e a barra (/).

## <a name="example"></a>Exemplo

```cpp
// C4138a.cpp
// compile with: /W1
int */*comment*/ptr;   // C4138 Ambiguous first delimiter causes warning
int main()
{
}
```

Esse aviso pode ser causado pela tentativa de aninhar comentários.

Esse aviso pode ser resolvido se você comentar seções de código que contenham comentários, coloque o código em um bloco **#if/#endif** e defina a expressão de controle como zero:

```cpp
// C4138b.cpp
// compile with: /W1
#if 0
int my_variable;   /* Declaration currently not needed */
#endif
int main()
{
}
```