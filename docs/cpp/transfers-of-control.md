---
title: Transferências de controle
ms.date: 11/04/2016
helpviewer_keywords:
- control flow, branching
- control flow, transferring control
ms.assetid: aa51e7f2-060f-4106-b0fe-331f04357423
ms.openlocfilehash: c9a46ccb1cf519080c5105855e41ecd3ebc23f77
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188045"
---
# <a name="transfers-of-control"></a>Transferências de controle

Você pode usar a instrução **goto** ou um rótulo **Case** em uma instrução **switch** para especificar um programa que ramificações após um inicializador. Esse código é inválido, a menos que a declaração que contém o inicializador esteja em um bloco delimitado pelo bloco em que a instrução de salto ocorre.

O exemplo a seguir mostra um loop que declara e inicializa os objetos `total`, `ch` e `i`. Há também uma instrução **goto** incorreta que transfere o controle após um inicializador.

```cpp
// transfers_of_control.cpp
// compile with: /W1
// Read input until a nonnumeric character is entered.
int main()
{
   char MyArray[5] = {'2','2','a','c'};
   int i = 0;
   while( 1 )
   {
      int total = 0;

      char ch = MyArray[i++];

      if ( ch >= '0' && ch <= '9' )
      {
         goto Label1;

         int i = ch - '0';
      Label1:
         total += i;   // C4700: transfers past initialization of i.
      } // i would be destroyed here if  goto error were not present
   else
      // Break statement transfers control out of loop,
      //  destroying total and ch.
      break;
   }
}
```

No exemplo anterior, a instrução **goto** tenta transferir o controle após a inicialização de `i`. No entanto, se `i` tivesse sido declarado, mas não inicializado, a transferência seria válida.

Os objetos `total` e `ch`, declarados no bloco que serve como a *instrução* da instrução **while** , são destruídos quando esse bloco é encerrado usando a instrução **Break** .
