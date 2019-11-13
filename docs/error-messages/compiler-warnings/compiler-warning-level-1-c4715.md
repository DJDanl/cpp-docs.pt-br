---
title: Aviso do compilador (nível 1) C4715
ms.date: 11/04/2016
f1_keywords:
- C4715
helpviewer_keywords:
- C4715
ms.assetid: 1c819bf7-0d8b-4f5e-b338-9cc292870439
ms.openlocfilehash: 268a26f5de1bb7f757a8e7cba6d3f5e6ddff882e
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052473"
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