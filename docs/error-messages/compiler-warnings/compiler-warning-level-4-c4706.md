---
title: Aviso do compilador (nível 4) C4706
ms.date: 11/04/2016
f1_keywords:
- C4706
helpviewer_keywords:
- C4706
ms.assetid: 89cd3f4f-812c-4a4b-9426-65a5a6d1b99c
ms.openlocfilehash: 2ff8794dcf29539b492f53bfdf6f0810988c0f72
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74989910"
---
# <a name="compiler-warning-level-4-c4706"></a>Aviso do compilador (nível 4) C4706

atribuição dentro de expressão condicional

O valor de teste em uma expressão condicional era o resultado de uma atribuição.

Uma atribuição tem um valor (o valor no lado esquerdo da atribuição) que pode ser usado legalmente em outra expressão, incluindo uma expressão de teste.

O exemplo a seguir gera C4706:

```cpp
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

O aviso ocorrerá mesmo se você dobrar os parênteses em volta da condição de teste:

```cpp
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

Se sua intenção for testar uma relação e não fazer uma atribuição, use o operador de `==`. Por exemplo, a linha a seguir testa se a e b são iguais:

```cpp
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

Se você pretende fazer seu valor de teste do resultado de uma atribuição, teste para garantir que a atribuição seja diferente de zero ou não nula. Por exemplo, o código a seguir não gerará este aviso:

```cpp
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
