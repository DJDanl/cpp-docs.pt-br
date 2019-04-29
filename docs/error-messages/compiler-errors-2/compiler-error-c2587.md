---
title: Erro do compilador C2587
ms.date: 11/04/2016
f1_keywords:
- C2587
helpviewer_keywords:
- C2587
ms.assetid: 7637a2c7-35d4-4b5a-a8f2-515a7bda98fd
ms.openlocfilehash: 08a576d5672f0df1cbec7269f83a3f182ce0e1c3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350500"
---
# <a name="compiler-error-c2587"></a>Erro do compilador C2587

'identifier': uso inválido de variável local como parâmetro padrão

Variáveis locais não são permitidas como parâmetros padrão.

O exemplo a seguir gera C2587:

```
// C2587.cpp
// compile with: /c
int i;
void func() {
   int j;
   extern void func2( int k = j );  // C2587 -- local variable
   extern void func3( int k = i );   // OK
}
```