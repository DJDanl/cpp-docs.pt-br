---
title: Erro do compilador C2293
ms.date: 11/04/2016
f1_keywords:
- C2293
helpviewer_keywords:
- C2293
ms.assetid: 17e7b4e2-368b-4dd7-a01b-d82be60f8e56
ms.openlocfilehash: c2c3760bcc7fcc84f914424d16a937cb3e9a0b09
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759094"
---
# <a name="compiler-error-c2293"></a>Erro do compilador C2293

' identifier ': inválido para ter uma variável de membro como um especificador de __based

Os especificadores para o modificador de `__based` devem ser ponteiros não membros.

O exemplo a seguir gera C2293:

```cpp
// C2293.cpp
// compile with: /c
class A {
   static int *i;
   void __based(i) *bp;   // C2293
   void *bp2;   // OK
};
```
