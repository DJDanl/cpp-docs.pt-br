---
title: Aviso do compilador (nível 1) C4006
ms.date: 11/04/2016
f1_keywords:
- C4006
helpviewer_keywords:
- C4006
ms.assetid: f1a59819-0fd2-4361-8e3a-99e4b514b8e1
ms.openlocfilehash: b589a4bd6b9e14ec926f634f12883e02bf450514
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164710"
---
# <a name="compiler-warning-level-1-c4006"></a>Aviso do compilador (nível 1) C4006

\#undef esperava um identificador

A diretiva de `#undef` não especificou um identificador para a definição. A diretiva é ignorada. Para resolver o aviso, certifique-se de especificar um identificador. O exemplo a seguir gera C4006:

```cpp
// C4006.cpp
// compile with: /W1
#undef   // C4006

// try..
// #undef TEST

int main() {
}
```
