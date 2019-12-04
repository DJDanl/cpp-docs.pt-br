---
title: Erro do compilador C2375
ms.date: 11/04/2016
f1_keywords:
- C2375
helpviewer_keywords:
- C2375
ms.assetid: 193c5e8b-1b20-4928-8a02-8c1cddaf2a26
ms.openlocfilehash: 926af13420ce80caf84876a12995946377366fd0
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745519"
---
# <a name="compiler-error-c2375"></a>Erro do compilador C2375

' função ': redefinição; vínculo diferente

A função já está declarada com um especificador de ligação diferente.

O exemplo a seguir gera C2375:

```cpp
// C2375.cpp
// compile with: /Za /c
extern void func( void );
static void func( void );   // C2375
static void func2( void );   // OK
```
