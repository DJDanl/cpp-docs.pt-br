---
title: Compilador aviso (nível 3) C4197
ms.date: 11/04/2016
f1_keywords:
- C4197
helpviewer_keywords:
- C4197
ms.assetid: f766feef-82b0-4d81-8a65-33628c7db196
ms.openlocfilehash: 15b2fba94bfc956775a1e454893e7509a32000e5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402236"
---
# <a name="compiler-warning-level-3-c4197"></a>Compilador aviso (nível 3) C4197

'type': volatile de alto nível em conversão é ignorado

O compilador detectou uma conversão para um tipo de valor r que é qualificado com [volátil](../../cpp/volatile-cpp.md), ou uma conversão de um tipo de valor r para algum tipo que é qualificado com volátil. Acordo com o padrão C (6.5.3), as propriedades associadas a tipos qualificados são significativas apenas para expressões l-value.

O exemplo a seguir gera C4197:

```
// C4197.cpp
// compile with: /W3
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigproc(int);
struct S
{
   int i;
} s;

int main()
{
   signal(SIGINT, sigproc);
   s.i = 1;
   S *pS = &s;
   for ( ; (volatile int)pS->i ; )   // C4197
      break;
   // for ( ; *(volatile int *)&pS->i ; )   // OK
   //    break;
}

void sigproc(int) // ctrl-C
{
   signal(SIGINT, sigproc);
   s.i = 0;
}
```