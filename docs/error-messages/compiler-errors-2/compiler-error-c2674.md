---
title: Erro do compilador C2674
ms.date: 11/04/2016
f1_keywords:
- C2674
helpviewer_keywords:
- C2674
ms.assetid: 7cbd70d8-d992-44d7-a5cb-dd8cf9c759d2
ms.openlocfilehash: eb56651967f8fdc33b7c76b29883b25295d752d0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456804"
---
# <a name="compiler-error-c2674"></a>Erro do compilador C2674

uma declaração de generic não é permitida neste contexto

Um genérico foi declarado incorretamente. Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2674.

```
// C2674.cpp
// compile with: /clr /c
void F(generic <class T> ref class R1);   // C2674
generic <class T> ref class R2 {};   // OK
```