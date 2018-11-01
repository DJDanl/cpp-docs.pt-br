---
title: Compilador aviso (nível 4) C4706
ms.date: 11/04/2016
f1_keywords:
- C4706
helpviewer_keywords:
- C4706
ms.assetid: 89cd3f4f-812c-4a4b-9426-65a5a6d1b99c
ms.openlocfilehash: e57470fcd8e7b014084b094c9ca5e39f0a86d85e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630009"
---
# <a name="compiler-warning-level-4-c4706"></a>Compilador aviso (nível 4) C4706

atribuição em expressão condicional

O valor de teste em uma expressão condicional foi o resultado de uma atribuição.

Uma atribuição tem um valor (o valor no lado esquerdo da atribuição) que pode ser usado legalmente em outra expressão, incluindo uma expressão de teste.

O exemplo a seguir gera C4706:

```
// C4706a.cpp
// compile with: /W4
int main()
{
   int a = 0, b = 0;
   if ( a  = b ) // C4706
   {
   }
}
```

O aviso ocorrerá mesmo se você duplicar os parênteses que delimitam a condição de teste:

```
// C4706b.cpp
// compile with: /W4
int main()
{
   int a = 0, b = 0;
   if ( ( a  =  b ) ) // C4706
   {
   }
}
```

Se sua intenção é uma relação de teste e não fazem uma atribuição, use o `==` operador. Por exemplo, a seguinte linha testes se um e b são iguais:

```
// C4706c.cpp
// compile with: /W4
int main()
{
   int a = 0, b = 0;
   if ( a == b )
   {
   }
}
```

Se você pretende fazer com que seu teste o resultado de uma atribuição de valor, de teste para garantir que a atribuição é diferente de zero ou não nulo. Por exemplo, o código a seguir não gerará este aviso:

```
// C4706d.cpp
// compile with: /W4
int main()
{
   int a = 0, b = 0;
   if ( ( a = b ) != 0 )
   {
   }
}
```