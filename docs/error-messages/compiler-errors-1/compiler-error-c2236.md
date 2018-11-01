---
title: Erro do compilador C2236
ms.date: 11/04/2016
f1_keywords:
- C2236
helpviewer_keywords:
- C2236
ms.assetid: 0b6771a7-a783-4729-9c3d-7a3339c432cc
ms.openlocfilehash: 988377d2995468c84b86872ab6f2b25f5c3df9f3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462641"
---
# <a name="compiler-error-c2236"></a>Erro do compilador C2236

token inesperado 'identifier'. Você esqueceu um ';'?

O identificador já está definido como um tipo e não pode ser substituído por um tipo definido pelo usuário.

O exemplo a seguir gera C2236:

```
// C2236.cpp
// compile with: /c
int class A {};  // C2236 "int class" is unexpected
int i;
class B {};
```