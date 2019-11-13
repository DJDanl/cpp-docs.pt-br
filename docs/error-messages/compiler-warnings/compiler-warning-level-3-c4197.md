---
title: Aviso do compilador (nível 3) C4197
ms.date: 11/04/2016
f1_keywords:
- C4197
helpviewer_keywords:
- C4197
ms.assetid: f766feef-82b0-4d81-8a65-33628c7db196
ms.openlocfilehash: d7c8cee42f17ad3301980852b8333ea37f5ca6be
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051775"
---
# <a name="compiler-warning-level-3-c4197"></a>Aviso do compilador (nível 3) C4197

' type ': volátil de nível superior em conversão é ignorado

O compilador detectou uma conversão em um tipo de valor r que é qualificado com [volátil](../../cpp/volatile-cpp.md)ou uma conversão de um tipo de valor r para algum tipo que é qualificado com volátil. De acordo com o padrão C (6.5.3), as propriedades associadas a tipos qualificados são significativas apenas para expressões l-Value.

O exemplo a seguir gera C4197:

```cpp
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