---
title: Compilador aviso (nível 1) C4715
ms.date: 11/04/2016
f1_keywords:
- C4715
helpviewer_keywords:
- C4715
ms.assetid: 1c819bf7-0d8b-4f5e-b338-9cc292870439
ms.openlocfilehash: f165ea3b54b78e2f8fae995815e309d55101244e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501225"
---
# <a name="compiler-warning-level-1-c4715"></a>Compilador aviso (nível 1) C4715

'function': nem todos os caminhos de controle retornam um valor

A função especificada potencialmente não pode retornar um valor.

## <a name="example"></a>Exemplo

```
// C4715a.cpp
// compile with: /W1 /LD
int func1( int i )
{
   if( i )
   return 3;  // C4715 warning, nothing returned if i == 0
}
```

Para evitar esse aviso, modifique o código para que todos os caminhos de atribuir um valor de retorno da função:

```
// C4715b.cpp
// compile with: /LD
int func1( int i )
{
   if( i ) return 3;
   else return 0;     // OK, always returns a value
}
```

É possível que seu código pode conter uma chamada para uma função que nunca retorna, como no exemplo a seguir:

```
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

Esse código também gera um aviso, pois o compilador não sabe disso `fatal` nunca retorna. Para impedir que esse código gera uma mensagem de erro, declare `fatal` usando [__declspec(noreturn)](../../cpp/noreturn.md).