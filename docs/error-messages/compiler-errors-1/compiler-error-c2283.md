---
title: Erro do compilador C2283
ms.date: 11/04/2016
f1_keywords:
- C2283
helpviewer_keywords:
- C2283
ms.assetid: 8a5b3175-b480-4598-a1f7-0b50504c5caa
ms.openlocfilehash: 1113236680241a80c462e382c8c9c7de342b5463
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50629990"
---
# <a name="compiler-error-c2283"></a>Erro do compilador C2283

'identifier': especificador puro ou substituição abstract especificador não permitido no struct sem nome

Uma função de membro de uma classe sem nome ou a estrutura é declarada com um especificador puro, que não é permitido.

O exemplo a seguir gera C2283:

```
// C2283.cpp
// compile with: /c
struct {
   virtual void func() = 0;   // C2283
};
struct T {
   virtual void func() = 0;   // OK
};
```