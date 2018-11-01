---
title: Erro do compilador C2979
ms.date: 11/04/2016
f1_keywords:
- C2979
helpviewer_keywords:
- C2979
ms.assetid: 98bd9043-ec44-451e-a482-3a8e35fc7464
ms.openlocfilehash: 5d9b8e025d96e448ec9494834eb1766cafd8b677
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531013"
---
# <a name="compiler-error-c2979"></a>Erro do compilador C2979

especializações explícitas não têm suporte em genéricos

Uma classe genérica foi declarada incorretamente.  Ver [genéricos](../../windows/generics-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2979.

```
// C2979.cpp
// compile with: /clr /c
generic <>
ref class Utils {};   // C2979 error

generic <class T>
ref class Utils2 {};   // OK
```