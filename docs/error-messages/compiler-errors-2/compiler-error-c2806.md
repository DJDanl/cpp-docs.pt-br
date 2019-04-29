---
title: Erro do compilador C2806
ms.date: 11/04/2016
f1_keywords:
- C2806
helpviewer_keywords:
- C2806
ms.assetid: 7c9ff1f4-1590-4c47-991d-b1075a173b48
ms.openlocfilehash: 1d37f5d1c6e253c01ae8a3b7640fb3ee4cf12534
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62281961"
---
# <a name="compiler-error-c2806"></a>Erro do compilador C2806

'operator operador' tem muitos parâmetros formais

Um operador sobrecarregado possui muitos parâmetros.

O exemplo a seguir gera C2806:

```
// C2806.cpp
// compile with: /c
class X {
public:
   X operator++ ( int, int );   // C2806 more than 1 parameter
   X operator++ ( int );   // OK
} ;
```