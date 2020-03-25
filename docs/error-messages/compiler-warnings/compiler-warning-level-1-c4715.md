---
title: Aviso do compilador (nível 1) C4715
ms.date: 11/04/2016
f1_keywords:
- C4715
helpviewer_keywords:
- C4715
ms.assetid: 1c819bf7-0d8b-4f5e-b338-9cc292870439
ms.openlocfilehash: 7dba86d591f18fd7c9c562078204916000d47384
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175318"
---
# <a name="compiler-warning-level-1-c4715"></a>Aviso do compilador (nível 1) C4715

' function ': nem todos os caminhos de controle retornam um valor

A função especificada pode potencialmente não retornar um valor.

## <a name="example"></a>Exemplo

```cpp
// C4715a.cpp
// compile with: /W1 /LD
int func1( int i )
{
   if( i )
   return 3;  // C4715 warning, nothing returned if i == 0
}
```

Para evitar esse aviso, modifique o código para que todos os caminhos atribuam um valor de retorno à função:

```cpp
// C4715b.cpp
// compile with: /LD
int func1( int i )
{
   if( i ) return 3;
   else return 0;     // OK, always returns a value
}
```

É possível que seu código possa conter uma chamada para uma função que nunca retorna, como no exemplo a seguir:

```cpp
// C4715c.cpp
// compile with: /W1 /LD
void fatal()
{
}
int glue()
{
   if(0)
      return 1;
   else if(0)
      return 0;
   else
      fatal();   // C4715
}
```

Esse código também gera um aviso, porque o compilador não sabe que `fatal` nunca retorna. Para impedir que esse código gere uma mensagem de erro, declare `fatal` usando [__declspec (noreturn)](../../cpp/noreturn.md).
