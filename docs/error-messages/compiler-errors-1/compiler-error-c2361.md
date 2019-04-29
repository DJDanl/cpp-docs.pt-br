---
title: Erro do compilador C2361
ms.date: 11/04/2016
f1_keywords:
- C2361
helpviewer_keywords:
- C2361
ms.assetid: efbdaeb9-891c-4f7d-97da-89088a8413f3
ms.openlocfilehash: ca03a42cbf746a1ef32d9c79c23de637f05b56fc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62364357"
---
# <a name="compiler-error-c2361"></a>Erro do compilador C2361

inicialização de 'identifier' é ignorada por rótulo 'default'

A inicialização de `identifier` pode ser ignorada em um `switch` instrução. Você não pode ir após uma declaração com um inicializador, a menos que a declaração é incluída em um bloco. (A menos que ela é declarada dentro de um bloco, a variável está dentro do escopo até o final do `switch` instrução.)

O exemplo a seguir gera C2361:

```
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

Solução possível:

```
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