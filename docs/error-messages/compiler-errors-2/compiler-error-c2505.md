---
title: Erro do compilador C2505
ms.date: 11/04/2016
f1_keywords:
- C2505
helpviewer_keywords:
- C2505
ms.assetid: b19f5c53-399d-425e-90db-fe3ca9b40858
ms.openlocfilehash: eabed85c61eaaa43b0106e0011f0357ece2e1ae1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221166"
---
# <a name="compiler-error-c2505"></a>Erro do compilador C2505

' Symbol ': ' __declspec (modificador) ' só pode ser aplicado a declarações ou definições de objetos globais ou membros de dados estáticos

Um **`__declspec`** modificador que é projetado para ser usado apenas no escopo global foi usado em uma função.

Para obter mais informações, consulte [AppDomain](../../cpp/appdomain.md) e [process](../../cpp/process.md).

O exemplo a seguir gera C2505:

```cpp
// C2505.cpp
// compile with: /clr

// OK
__declspec(process) int ii;
__declspec(appdomain) int jj;

int main() {
   __declspec(process) int i;   // C2505
   __declspec(appdomain) int j;   // C2505
}
```
