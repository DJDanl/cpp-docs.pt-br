---
title: Erro do compilador C2361
ms.date: 11/04/2016
f1_keywords:
- C2361
helpviewer_keywords:
- C2361
ms.assetid: efbdaeb9-891c-4f7d-97da-89088a8413f3
ms.openlocfilehash: b95c6459c0ff093d22f3e754f2c7fd6564d2b296
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221192"
---
# <a name="compiler-error-c2361"></a>Erro do compilador C2361

a inicialização de ' identifier ' é ignorada pelo rótulo ' default '

A inicialização de `identifier` pode ser ignorada em uma **`switch`** instrução. Não é possível pular uma declaração com um inicializador, a menos que a declaração seja colocada em um bloco. (A menos que seja declarado dentro de um bloco, a variável estará dentro do escopo até o final da **`switch`** instrução.)

O exemplo a seguir gera C2361:

```cpp
// C2361.cpp
void func( void ) {
   int x;
   switch (x) {
   case 0 :
      int i = 1;
      { int j = 1; }
   default :   // C2361 error
      int k = 1;
   }
}
```

Resolução possível:

```cpp
// C2361b.cpp
// compile with: /c
void func( void ) {
   int x = 0;
   switch (x) {
   case 0 :
      { int j = 1; int i = 1;}
   default :
      int k = 1;
   }
}
```
