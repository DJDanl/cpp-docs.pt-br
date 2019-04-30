---
title: Erro do compilador C2979
ms.date: 11/04/2016
f1_keywords:
- C2979
helpviewer_keywords:
- C2979
ms.assetid: 98bd9043-ec44-451e-a482-3a8e35fc7464
ms.openlocfilehash: e9b0af0d17ef57f19e051165b16632e3180159cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62395307"
---
# <a name="compiler-error-c2979"></a>Erro do compilador C2979

especializações explícitas não têm suporte em genéricos

Uma classe genérica foi declarada incorretamente.  Ver [genéricos](../../extensions/generics-cpp-component-extensions.md) para obter mais informações.

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