---
title: Aviso do compilador (nível 1) C4545
ms.date: 11/04/2016
f1_keywords:
- C4545
helpviewer_keywords:
- C4545
ms.assetid: 43f8f34f-ed46-4661-95c0-c588c577ff73
ms.openlocfilehash: 83613ec6a3ba2d3c1059b75e499b94f150cbe5a2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186298"
---
# <a name="compiler-warning-level-1-c4545"></a>Aviso do compilador (nível 1) C4545

expressão antes da vírgula é avaliada para uma função que está ausente em uma lista de argumentos

O compilador detectou uma expressão de vírgula mal formada.

Esse aviso está desativado por padrão. Para obter mais informações, consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

O exemplo a seguir gera C4545:

```cpp
// C4545.cpp
// compile with: /W1
#pragma warning (default : 4545)

void f() { }

int main()
{
   *(&f), 10;   // C4545
   // try the following line instead
   // (*(&f))(), 10;
}
```
