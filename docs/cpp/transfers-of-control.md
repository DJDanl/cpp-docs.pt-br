---
title: Transferências de controle
ms.date: 11/04/2016
helpviewer_keywords:
- control flow, branching
- control flow, transferring control
ms.assetid: aa51e7f2-060f-4106-b0fe-331f04357423
ms.openlocfilehash: ef437d0a691ceff72485be1ff9584052f540031a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232177"
---
# <a name="transfers-of-control"></a>Transferências de controle

Você pode usar a **`goto`** instrução ou um **`case`** rótulo em uma **`switch`** instrução para especificar um programa que ramificações após um inicializador. Esse código é inválido, a menos que a declaração que contém o inicializador esteja em um bloco delimitado pelo bloco em que a instrução de salto ocorre.

O exemplo a seguir mostra um loop que declara e inicializa os objetos `total`, `ch` e `i`. Há também uma instrução errada **`goto`** que transfere o controle após um inicializador.

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

No exemplo anterior, a **`goto`** instrução tenta transferir o controle após a inicialização de `i` . No entanto, se `i` tivesse sido declarado, mas não inicializado, a transferência seria válida.

Os objetos `total` e `ch` , declarados no bloco que serve como a *instrução* da **`while`** instrução, são destruídos quando esse bloco é encerrado usando a **`break`** instrução.
