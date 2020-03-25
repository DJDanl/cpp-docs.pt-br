---
title: Aviso do compilador (nível 2) C4309
ms.date: 11/04/2016
f1_keywords:
- C4309
helpviewer_keywords:
- C4309
ms.assetid: cb3f41ef-fd8a-4def-baa1-924e751fca68
ms.openlocfilehash: a307d941f6225c9e431ad71a6385229bd01957f9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161861"
---
# <a name="compiler-warning-level-2-c4309"></a>Aviso do compilador (nível 2) C4309

' Conversion ': truncamento do valor constante

A conversão de tipo faz com que uma constante exceda o espaço alocado para ela. Talvez seja necessário usar um tipo maior para a constante.

O exemplo a seguir gera C4309:

```cpp
// C4309.cpp
// compile with: /W2
int main()
{
   char c = 128;   // C4309
}
```
